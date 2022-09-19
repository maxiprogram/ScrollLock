#include <iostream>
#include <fstream>
#include <unistd.h>
#include <errno.h>
#include <string.h>

using namespace std;

int main()
{
    fstream file_brightness;
    while (true) {
        //? number device path /sys/class/leds/input?
        file_brightness.open("/sys/class/leds/input3::scrolllock/brightness");
        if(file_brightness.is_open()) {
            char flag;
            flag = file_brightness.get();
            if(flag == '0') {
                file_brightness<<'1';
            }
            file_brightness.close();
        } else {
            cerr<<"Error: Open file Code="<<errno<<" Description="<<strerror(errno)<<endl;
            //return 1;
        }
        sleep(1);
    }

    return 0;
}
