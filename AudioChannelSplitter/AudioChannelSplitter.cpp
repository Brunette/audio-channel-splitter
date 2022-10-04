#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <string>
#include "wav_header.h"
#include "FileUtility.h" 

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
    handleFileInput(&filePath, argc, argv);

    FILE* audioFile;
    if (!openAudioFile(&audioFile, filePath)) {
        return;
    }


}
