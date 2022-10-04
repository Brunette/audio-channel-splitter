#include "pch.h"
#include "CppUnitTest.h"
#include "../AudioChannelSplitter/FileUtility.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::string;

namespace UnitTestsFileUtility
{
	TEST_CLASS(UnitTestsFileUtility)
	{
	public:

		TEST_METHOD(handleFileInput_goodInput)
		{
			char* argv[] = { "app.exe", "filepath" };
			int argc = 2;
			const char* filePath;
			handleFileInput(&filePath, argc, argv);
			Assert::AreEqual(filePath, "filepath");
		}

		TEST_METHOD(getFileExtension_wav_basic)
		{
			string wavePath = "audio.wav";
			string ext = "wav";

			Assert::AreEqual(getFileExt(wavePath), ext);
			wavePath = "audio.mp3";
			ext = "mp3";
			Assert::AreEqual(getFileExt(wavePath), ext);
			wavePath = "audio.pcm";
			ext = "pcm";
			Assert::AreEqual(getFileExt(wavePath), ext);
		}

		TEST_METHOD(getFileExtension_wav_specialcases_good)
		{
			string wav = "wav";
			string wavePath = ".wav";
			Assert::AreEqual(getFileExt(wavePath), wav);
			wavePath = "still.a.file.event.though.its.really.long.wav";
			Assert::AreEqual(getFileExt(wavePath), wav);
		}

		TEST_METHOD(getFileExtension_wav_bad)
		{
			string wav = "wav";
			string wavePath = "thisisnotwav";
			Assert::AreNotEqual(getFileExt(wavePath), wav);
			wavePath = "";
			Assert::AreNotEqual(getFileExt(wavePath), wav);
			wavePath = "isthis.wav.";
			Assert::AreNotEqual(getFileExt(wavePath), wav);
		}


	};
}
