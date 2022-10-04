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
	static size_t readHeader(pse_hdr* pseHeader, std::string filePath, FILE* audioFile);

};
