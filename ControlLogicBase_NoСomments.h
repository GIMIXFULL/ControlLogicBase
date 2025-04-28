#pragma once
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <atomic>

using namespace std;

class program
{
private:
    atomic <bool> comm_end;
    atomic <bool> comm_start;
    void setCommEndFalse() { comm_end = false; }
    void command_control_flow()
    {
        comm_start = true;
        while (comm_end)
        {
            char c;
            c = _getch();

            if (c == 27)
            {
                cout << "\nExiting program." << endl;
                setCommEndFalse();
            }
        }
    }
public:
    program() : comm_end(true), comm_start(false) {}
    void start()
    {
        thread flow_1(&program::command_control_flow, this);
        this_thread::sleep_for(chrono::microseconds(100));
        if (comm_start == true)
        {
            while (comm_end)
            {

            }
        }
        else
        {
            cout << "Error: Command control flow did not start." << endl;
            setCommEndFalse();
        }
        flow_1.join();
    }
};