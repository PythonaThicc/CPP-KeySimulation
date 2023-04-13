#include <Windows.h>
#include <conio.h>
#include <iostream>

// Function to simulate key press
void pressKey(char key) {
    INPUT ip;
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the 'a' key
    ip.ki.wVk = key; // virtual-key code for the key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the 'a' key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}

int main() {

    std::cout << "Press [VK_UP] to press [W]" << std::endl;
    std::cout << "Press [VK_LEFT] to press [A]" << std::endl;
    std::cout << "Press [VK_DOWN] to press [S]" << std::endl;
    std::cout << "Press [VK_RIGHT] to press [D]" << std::endl;
    std::cout << "Press [LCTRL] to change the pixel color to blue (buggy)" << std::endl;

    HDC dng = GetDC(NULL);


    while (true) {

        if (GetAsyncKeyState(VK_UP)) {
            std::cout << "Key W Pressed" << '\n';
            Sleep(1);
            pressKey('W');
            Sleep(1);
        }
        else if (GetAsyncKeyState(VK_DOWN)) {
            std::cout << "Key S Pressed" << '\n';
            Sleep(1);
            pressKey('S');
            Sleep(1);
        }
        else if (GetAsyncKeyState(VK_LEFT)) {
            std::cout << "Key A Pressed" << '\n';
            Sleep(1);
            pressKey('A');
            Sleep(1);
        }
        else if (GetAsyncKeyState(VK_RIGHT)) {
            std::cout << "Key D Pressed" << '\n';
            Sleep(1);
            pressKey('D');
            Sleep(1);
        }
        else if (GetAsyncKeyState(0x46)) {
            std::cout << "Left CLick Pressed" << '\n';
            Sleep(1);
            system("CLS");
            Sleep(1);
            keybd_event(VK_LBUTTON, 0, KEYEVENTF_EXTENDEDKEY, 0);
            Sleep(1);
            keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
            Sleep(1);
        }
        else if (GetAsyncKeyState(0x52)) {
            std::cout << "Right CLick Pressed" << '\n';
            Sleep(1);
            system("CLS");
            Sleep(1);
            keybd_event(VK_RBUTTON, 0, KEYEVENTF_EXTENDEDKEY, 0);
            Sleep(1);
            keybd_event(VK_RBUTTON, 0, KEYEVENTF_KEYUP, 0);
            Sleep(1);
        }
        else if (GetAsyncKeyState(0xA3)) {
            std::cout << "Pixel Set" << '\n';
            Sleep(20);

            for (int i = 1000; i <= 1015; i++)
                for (int j = 500; j <= 515; j++)
                    SetPixel(dng, i, j, RGB(0, 0, 255));

            COLORREF c = GetPixel(dng, 1000, 500);

            std::cout << (int)GetRValue(c) << '\n';
            std::cout << (int)GetGValue(c) << '\n';
            std::cout << (int)GetBValue(c) << '\n';

            ReleaseDC(NULL, dng);

        }

    }
    return 0;
}
