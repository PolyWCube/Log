#pragma once

#include <string>
#include <iostream>

#include <fstream>

#include <ctime>
#include <chrono>

#include <vector>
#include <filesystem>

namespace Custom {
	namespace Log {
		enum Mode { trace, debug, status, success, warn, error, fatal, unknown };
		enum Color { lGray, blue, green, dGreen, yellow, red, dRed, pink };

		const std::string timestampToken[23]{
			"day",
			"month",
			"year",
			"second",
			"minute",
			"hour",
			"/", "|", ":", ";", "-", "+",
			"[", "]", "(", ")", "{", "}", "<", ">",
			",", ".", " "
		};

		const std::string token[22]{
			"timestamp",
			"mode",
			"message",
			"color ",
			"reset ",
			"/", "|", ":", ";", "-", "+",
			"[", "]", "(", ")", "{", "}", "<", ">",
			",", ".", " "
		};

		class Logger {
		public:
			Logger(const std::string& logDirectory = "./log/", const std::string& fileFormat = "day-month-year...hour-minute", const std::string& timestampFormat = "second:minute:hour", const std::string& logFormat = "[timestamp] color mode reset : message") : timestampFormat(TimestampFormat(timestampFormat)), fileFormat(TimestampFormat(fileFormat) + ".txt"), logDirectory(logDirectory) {
				LogFormat(logFormat);

				std::filesystem::create_directory(logDirectory);

				CreateFile();
			}
			~Logger() { file.close(); }

			void Log(std::string message, Mode mode);

			void SetTimestampFormat(const std::string& format);
			void SetLogFormat(const std::string& format);

			void SetFileDirectory(const std::string& directory);
			void SetFileNameFormat(const std::string& format);
			void CreateFile(const std::string& name);
			void CreateFile();

		private:
			void LogFormat(std::string format);
			std::string TimestampFormat(std::string format);

			inline std::string GetTimestamp(const std::string& format);

			inline static std::string GetMode(Mode mode);
			inline static std::string GetColor(Mode mode);
			inline static std::string GetColor(Color color);

			void FlushDirectory();

			std::ofstream file;
			std::string logDirectory;

			std::vector<std::string> logFormat;
			std::string timestampFormat;
			std::string fileFormat;
		};
	}
}