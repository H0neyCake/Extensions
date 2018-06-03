#include <stdio.h>
#include <ctime>
#include <string>
#define VERSION "0.1"
extern "C"
{
	//--- Called by Engine on extension load 
	__attribute__((dllexport)) void RVExtensionVersion(char *output, int outputSize);
	//--- STRING callExtension STRING
	__attribute__((dllexport)) void RVExtension(char *output, int outputSize, const char *function);
	//--- STRING callExtension ARRAY
	__attribute__((dllexport)) int RVExtensionArgs(char *output, int outputSize, const char *function, const char **args, int argsCnt)
}
void RVExtension(char *output, int outputSize, const char *function)
{
    std::time_t t = std::time(nullptr);
    std::string s = std::to_string(t);
    strncpy(output, s.c_str(), outputSize);
};
int RVExtensionArgs(char *output, int outputSize, const char *function, const char **args, int argsCnt)
{
    std::time_t t = std::time(nullptr);
    std::string s = std::to_string(t);
    strncpy(output, s.c_str(), outputSize);
};
void RVExtensionVersion(char *output, int outputSize)
{
	strncpy(output, VERSION, outputSize);
};
