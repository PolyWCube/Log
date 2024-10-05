#pragma once

#ifdef CUSTOM_PLATFORM_WINDOWS
	#define DAY "%d"
	#define MONTH "%m"
	#define YEAR "%y"

	#define SECOND "%S"
	#define MINUTE "%M"
	#define HOUR "%H"

	#define NEW_LINE '\n'
#else Only support Windows
#endif