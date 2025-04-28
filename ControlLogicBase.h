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
    // Флаг для сигнализации завершения программы. 
    // Flag to signal the end of the program.
    atomic <bool> comm_end;
    // Флаг, показывающий, начался ли поток управления командами.
    // Flag indicating if the command control flow has started.
    atomic <bool> comm_start;
    // Устанавливает флаг `comm_end` в false, сигнализируя программе о завершении.
    // Sets the `comm_end` flag to false, signaling the program to terminate.
    void setCommEndFalse() { comm_end = false; }
    // Эта функция обрабатывает ввод с клавиатуры в отдельном потоке.
    // This function handles keyboard input in a separate thread.
    void command_control_flow()
    {
        // Помечаем, что поток управления командами запущен.
        // Mark that the command control flow has started.
        comm_start = true;
        while (comm_end)
        {
            char c;
            // Получаем символ из консоли, не дожидаясь нажатия Enter.
            // Get a character from the console without waiting for Enter.
            c = _getch();

            // Здесь пишется логика для обработки различных нажатий клавиш.
            // Here you write the logic for handling different key presses.

            if (c == 27) // Нажата клавиша Escape. | Escape key pressed.
            {
                cout << "\nExiting program." << endl;
                setCommEndFalse(); // Даём сигнал основному циклу для выхода. | Signal the main loop to exit.
            }
        }
    }
public:
    // Конструктор: Инициализирует `comm_end` в true и `comm_start` в false.
    // Constructor: Initializes `comm_end` to true and `comm_start` in false.
    program() : comm_end(true), comm_start(false) {}
    // Запускает программу, создавая и управляя потоком управления.
    // Starts the program, creating and managing the control flow thread.
    void start()
    {
        // Создаём поток для обработки ввода команд.
        // Create a thread to handle command input.
        thread flow_1(&program::command_control_flow, this);
        // Даём потоку управления командами немного времени для запуска.
        // Give the command control thread a little time to start.
        this_thread::sleep_for(chrono::microseconds(100));
        if (comm_start == true) // Checking whether the control flow has started. | Проверка на то запустился ли поток управления.
        {
            while (comm_end)
            {
                // Здесь находится основной цикл программы, где вы реализуете логику своей игры или другие задачи.
                // Here is the main program loop where you would implement your game logic or other tasks.
            }
        }
        else
        {
            cout << "Error: Command control flow did not start." << endl;
            // Убеждаемся, что программа завершается, если поток управления не запустился.
            // Ensure program exits cleanly if the control flow fails to start.
            setCommEndFalse();
        }
        // Ожидаем завершения потока управления.
        // Wait for the control flow thread to finish.
        flow_1.join();
    }
};

//Keycodes reference. | Справочник кодов клавиш.
/*

KEY NAME                DEC          HEX
Esc	                    1	         0x1
← Backspace	            14	         0x0E
Tab ↹	                15	         0x0F
↵ Enter	                28	         0x1C
⇧ Shift L	            42	         0x2A
⇧ Shift R	            54           0x36
Ctrl L	                29	         0x1D
Ctrl R	                285	         0x11D
Alt L	                56	         0x38
Alt R	                312	         0x138
⊞ Win L	                91	         0x5B
⊞ Win R	                92	         0x5C
⇪ Caps Lock	            58	         0x3A
Num Lock	            69	         0x45
Scrol Lock	            70	         0x46
Pause/Break	            69	         0x45
Ctrl + Pause/Break	    326	         0x146
End	                    79	         0x4F
Home	                71	         0x47
space	                57	         0x39
Page Up	                73	         0x49
Page Down	            81	         0x51
Clear	                76	         0x4C
←	                    75	         0x4B
↑	                    72	         0x48
→	                    77	         0x4D
↓	                    80	         0x50
PrtSc	                311	         0x137
Insert	                82	         0x52
Delete	                83	         0x53
0	                    11	         0xB
1	                    2	         0x2
2	                    3	         0x3
3	                    4	         0x4
4	                    5	         0x5
5	                    6	         0x6
6	                    7	         0x7
7	                    8	         0x8
8	                    9	         0x9
9	                    10	         0xA
A	                    30	         0x1E
B	                    48	         0x30
C	                    46	         0x2E
D	                    32	         0x20
E	                    18	         0x12
F	                    33	         0x21
G	                    34	         0x22
H	                    35	         0x23
I	                    23	         0x17
J	                    36	         0x24
K	                    37	         0x25
L	                    38	         0x26
M	                    50	         0x32
N	                    49	         0x31
O	                    24	         0x18
P	                    25	         0x19
Q	                    16	         0x10
R	                    19	         0x13
S	                    31	         0x1F
T	                    20	         0x14
U	                    22	         0x16
V	                    47	         0x2F
W	                    17	         0x11
X	                    45	         0x2D
Y	                    21	         0x15
Z	                    44	         0x2C
Context Menu	        349	         0x15D
Numpad 0	            82	         0x52
Numpad 1	            79	         0x4F
Numpad 2	            80	         0x50
Numpad 3	            81	         0x51
Numpad 4	            75	         0x4B
Numpad 5	            76	         0x4C
Numpad 6	            77	         0x4D
Numpad 7	            71	         0x47
Numpad 8	            72	         0x48
Numpad 9	            73	         0x49
Numpad *	            55	         0x37
Numpad +	            78	         0x4E
Numpad -	            74	         0x4A
Numpad . (Del)	        83	         0x53
Numpad /	            53	         0x35
Numpad Enter	        284	         0x11c
F1	                    59	         0x3B
F2	                    60	         0x3C
F3	                    61	         0x3D
F4	                    62	         0x3E
F5	                    63	         0x3F
F6	                    64	         0x40
F7	                    65	         0x41
F8	                    66	         0x42
F9	                    67	         0x43
F10	                    68	         0x44
F11	                    87	         0x57
F12	                    88	         0x58
F13	                    124	         0x7C
F14	                    125	         0x7D
F15	                    126	         0x7E
F16	                    127	         0x7F
F17	                    128	         0x80
F18	                    129	         0x81
F19	                    130	         0x82
F20	                    131	         0x83
F21	                    132	         0x84
F22	                    133	         0x85
F23	                    134	         0x86
F24	                    135	         0x87
; :	                    39	         0x27
- _	                    12	         0x0C
= +	                    13	         0x0D
< ,	                    51	         0x33
. >	                    52	         0x34
/ ?	                    53	         0x35
~	                    41	         0x29
[ {	                    26	         0x1A
] }	                    27	         0x1B
' "	                    40	         0x28
|	                    43	         0x2B

*/