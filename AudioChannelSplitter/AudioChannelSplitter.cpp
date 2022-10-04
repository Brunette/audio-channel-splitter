#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <string>
#include "pseudo_header.h"
#include "wav_header.h"
#include "FileUtility.h" 
#include "AudioHeaderReader.h" 

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
    static const uint16_t BUFFER_SIZE = 4096;    
    pse_hdr pseHeader;
    
    const char* filePath;
    handleFileInput(&filePath, argc, argv);

    FILE* audioFile;
    if (!openAudioFile(&audioFile, filePath)) {
        return 0;
    }

   

    string audioExt = getFileExt(filePath);
    
    size_t bytesRead;
    
    AudioHeaderReader::readHeader(&pseHeader, filePath, audioFile);
    
    
}
