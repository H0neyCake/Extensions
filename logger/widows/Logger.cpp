#include "stdafx.h"
#include <fstream>
#include <time.h>
#include <string>

extern "C"
{
	__declspec (dllexport) void __stdcall RVExtension(char *output, int outputSize, const char *function);
};

using namespace std;

void __stdcall RVExtension(char *output, int outputSize, const char *function)
{
	//Output it as the .dll result to arma 3
	strncpy_s(output, outputSize, "done", _TRUNCATE);

	//Get current Server Time for loggin
	time_t currentTime;
	struct tm *localTime;

	time(&currentTime);                   // Get the current time
	localTime = localtime(&currentTime);  // Convert the current time to the local time

	//Convert them to strings
	string Day = to_string(localTime->tm_mday);
	string Month = to_string(localTime->tm_mon + 1);
	string Year = to_string(localTime->tm_year + 1900);
	string Hour = to_string(localTime->tm_hour);
	string Min = to_string(localTime->tm_min);
	string Sec = to_string(localTime->tm_sec);

	//Create Dir for Logging
	CreateDirectoryA("@Arma3Log/Arma3Logs", NULL);

	//define the path and filename and log it.
	string logname = string("@Arma3Log/Arma3Logs/") + Day + "-" + Month + "-" + Year + ".txt";
	std::ofstream log(logname, std::ios_base::app | std::ios_base::out);
	log << Day << "-" << Month << "-" << Year << " - " << Hour << ":" << Min << ":" << Sec << " :: " << function << "\n";
};
