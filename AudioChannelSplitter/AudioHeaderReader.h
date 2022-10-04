#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <string>
#include "wav_header.h"
#include "pseudo_header.h"
#include "FileUtility.h"

class AudioHeaderReader
{
public:

	/// <summary>
	/// Takes the filePath and reads the extension. Based off the extension reads audioFile and populates header; Returns number of bytes read from header
	/// </summary>
	/// <param name="pseHeader"></param>
	/// <param name="filePath"></param>
	/// <param name="audioFile"></param>
	/// <returns></returns>
	static size_t readHeader(pse_hdr* pseHeader, std::string filePath, FILE* audioFile);
private:

	/// <summary>
	/// Internal Method used to parse wav header files
	/// </summary>
	/// <param name="pseHeader"></param>
	/// <param name="audioFile"></param>
	/// <returns></returns>
	static size_t readWav(pse_hdr* pseHeader, FILE* audioFile);

	/// <summary>
	/// Internal Method used to parse PCM header files. Nead filePath to getfileSize
	/// </summary>
	/// <param name="pseHeader"></param>
	/// <param name="filePath"></param>
	/// <param name="audioFile"></param>
	/// <returns></returns>
	static size_t readPcm(pse_hdr* pseHeader, std::string filePath, FILE* audioFile);

};
