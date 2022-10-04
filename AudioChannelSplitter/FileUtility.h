#pragma once
#include <string>
using std::string;

void handleFileInput(const char** filePath, int argc, char* argv[]) {
    string input;
    if (argc <= 1)
    {
        // if arg was not given, prompt;
        cout << "Enter file name: ";
        cin >> input;
        cin.get();
        *filePath = input.c_str();
    }
    else
    {
        *filePath = argv[1];
        cout << "File name from args: " << *filePath << endl;
    }
    return;
}

string openAudioFile(string filePath) {
    FILE* audioFile;
    errno_t err;
    if ((err = fopen_s(&audioFile, filePath, "r")) != 0)
    {
        fprintf(stderr, "Unable to open wave file: %s\n", filePath);
        return 1;
    }
};