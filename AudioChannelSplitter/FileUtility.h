#pragma once
#include <string>
#include <iostream>
#include <string>
#include <fstream>

void handleFileInput(const char** filePath, int argc, char* argv[]) {
    std::string input;
    if (argc <= 1)
    {
        // if arg was not given, prompt;
        std::cout << "Enter file name: ";
        std::cin >> input;
        std::cin.get();
        *filePath = input.c_str();
    }
    else
    {
        *filePath = argv[1];
        std::cout << "File name from args: " << *filePath << std::endl;
    }
    return;
}

int openAudioFile(FILE** audioFile, const char* filePath) {
    errno_t err;
    if ((err = fopen_s(audioFile, filePath, "r")) != 0)
    {
        fprintf(stderr, "Unable to open wave file: %s\n", filePath);
        return 0;
    }
    return 1;
};

std::string getFileExt(std::string fname) {
    return fname.substr(fname.find_last_of(".") + 1);
}
