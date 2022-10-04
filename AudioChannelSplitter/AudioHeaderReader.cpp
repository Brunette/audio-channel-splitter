#include "AudioHeaderReader.h"

size_t AudioHeaderReader::readHeader(pse_hdr* pseHeader, std::string filePath, FILE* audioFile) {

	std::string audioExt = getFileExt(filePath);
	size_t bytesRead = 0;
	if (audioExt == "wav")
	{
		bytesRead = readWav(pseHeader, audioFile);
	}
	else if (audioExt == "pcm")
	{
		bytesRead = readPcm(pseHeader, filePath, audioFile);
	}
	return bytesRead;
}

size_t readWav(pse_hdr* pseHeader, FILE* audioFile) {
	int headerSize = sizeof(wav_hdr), fileLength = 0;
	wav_hdr wavHeader;
	size_t bytesRead;
	bytesRead = fread(&wavHeader, 1, headerSize, audioFile);
	pseHeader->ChunkSize = wavHeader.bitsPerSample;
	pseHeader->BytesPerSample = wavHeader.bitsPerSample / 8;
	pseHeader->NumSamples = wavHeader.ChunkSize / pseHeader->BytesPerSample;
	pseHeader->ChunkSize = wavHeader.ChunkSize;
	pseHeader->NumOfChan = wavHeader.NumOfChan;
	return bytesRead;
}

size_t readPcm(pse_hdr* pseHeader, std::string filePath, FILE* audioFile) {
	pseHeader->ChunkSize = getFileSize(filePath);
	pseHeader->BitsPerSample = 8;
	pseHeader->BytesPerSample = pseHeader->BitsPerSample / 8;
	pseHeader->NumOfChan = 2;
	pseHeader->NumSamples = pseHeader->ChunkSize / pseHeader->BytesPerSample;
	return 0;
}