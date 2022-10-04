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
        //Failed to open file so exit;
        return 0; 
    }

    size_t bytesRead = AudioHeaderReader::readHeader(&pseHeader, filePath, audioFile);

    /* TODO: 
    *  1) Read bytes from Data Chunk into buffer.    
    *  2) Learn how Channel/Samples are stored in Data Chunk
    *       2a) I believe within each sample we see each SubChannelSample. So alterating subSamples Left | Right | Left | Right
    *       2b) Use pse_header data to calculate Sample size
    *  3) From this data chunk, parse Left and Right channels into their own buffer. Possibly directly into their own files.
    *       3a) Open left/right file streams and << alterating bytes into alternating fileStreams
    *  4) It might be necessary to readd update WAV headers, if mono .wav output is desired. Otherwise can be saved as PCM
    *  5) Cleanup
    *       5a) Close any open filestreams and files (leftfs,rightfs,audioFilm)
    *       5b) Delete any buffers
    */



    /* Useful ? This should read the audioFile into a buffer */
    //int8_t* buffer = new int8_t[BUFFER_SIZE];
    //while ((bytesRead = fread(buffer, sizeof buffer[0], BUFFER_SIZE / (sizeof buffer[0]), audioFile)) > 0){

    
}
