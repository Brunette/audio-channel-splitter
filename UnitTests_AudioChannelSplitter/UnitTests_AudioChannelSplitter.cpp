#include "pch.h"
#include "CppUnitTest.h"
#include "../AudioChannelSplitter/FileUtility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsAudioChannelSplitter
{
	TEST_CLASS(UnitTestsAudioChannelSplitter)
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

	};
}
