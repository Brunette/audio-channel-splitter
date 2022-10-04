#pragma once
#include <string>
#include <iostream>
#include <string>
#include <fstream>

void handleFileInput(const char** filePath, int argc, char* argv[]);
int openAudioFile(FILE** audioFile, const char* filePath);
std::string getFileExt(std::string fname);
long getFileSize(std::string filename);