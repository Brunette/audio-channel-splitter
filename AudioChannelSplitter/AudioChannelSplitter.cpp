#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <string>
#include "pseudo_header.h"
#include "wav_header.h"
#include "FileUtility.h" 

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

    if (audioExt == "wav")
    {
        int headerSize = sizeof(wav_hdr), fileLength = 0;
        wav_hdr wavHeader;
        bytesRead = fread(&wavHeader, 1, headerSize, audioFile);
        cout << "Header Read " << bytesRead << " bytes." << endl;
        pseHeader.ChunkSize = wavHeader.bitsPerSample;
        pseHeader.BytesPerSample = wavHeader.bitsPerSample / 8;
        pseHeader.NumSamples = wavHeader.ChunkSize / pseHeader.BytesPerSample;
        pseHeader.ChunkSize = wavHeader.ChunkSize;
        pseHeader.NumOfChan = wavHeader.NumOfChan;
    }
    else if (audioExt == "pcm")
    {
        pseHeader.ChunkSize = getFileSize(filePath);
        pseHeader.BitsPerSample = 8;
        pseHeader.BytesPerSample = pseHeader.BitsPerSample / 8;        
        pseHeader.NumOfChan = 2;
        pseHeader.NumSamples = pseHeader.ChunkSize / pseHeader.BytesPerSample;
    }
    
}
