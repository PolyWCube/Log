# Log
A customizable, neat, opensource, simple log system, header include only.
Be able to create log file in target directory
# Requirement
System: Window
Preprocessor: _CRT_SECURE_NO_WARNINGS; PLATFORM_WINDOWS
C++ version: ISO C++20 standard
# Usage
Example:
```
#include "include/Log.hpp"

int main() {
	Logger logger;

	logger.Log("Hello World", Mode::trace);

	return 0;
}
```
Logger function call:
```
Logger(const std::string& logDirectory = "./log/", const std::string& fileFormat = "day-month-year...hour-minute", const std::string& timestampFormat = "second:minute:hour", const std::string& logFormat = "[timestamp] color mode reset : message");

void Log(std::string message, Mode mode); // Log Message

void SetTimestampFormat(const std::string& format); // Customize Log Message Timestamp
void SetLogFormat(const std::string& format); // Customize Log Format

void SetFileDirectory(const std::string& directory); // Customize Log Output File Directory
void SetFileNameFormat(const std::string& format);  // Customize Log Output File Name (Timestamp Format)
void CreateFile(const std::string& name); // Create New Log File With Target Name
void CreateFile(); // Create New Log File With File Format Name
```