#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <string>
#include "wav_header.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
    static const uint16_t BUFFER_SIZE = 4096;
    wav_hdr wavHeader;
    int headerSize = sizeof(wav_hdr), fileLength = 0;

    const char* filePath;
    string input;
    if (argc <= 1)
    {
        cout << "Enter file name: ";
        cin >> input;
        cin.get();
        filePath = input.c_str();
    }
    else
    {
        filePath = argv[1];
        cout << "File name from args: " << filePath << endl;
    }
}
