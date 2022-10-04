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

};
