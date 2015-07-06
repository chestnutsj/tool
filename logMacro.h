#ifndef LOG_MACRO_H
#define LOG_MACRO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <log4cplus/logger.h>
#include "log4plusUnit.h"

using log4cplus::DEBUG_LOG_LEVEL;
using log4cplus::INFO_LOG_LEVEL;
using log4cplus::WARN_LOG_LEVEL;
using log4cplus::FATAL_LOG_LEVEL;
using log4cplus::ERROR_LOG_LEVEL;
using log4cplus::Logger;

#define DEFAULTLOGCONFIG(file) if(logStart(file) == 0) { \
		try{\
		log4cplus::Logger defaultLog = getInstance(LOG4CPLUS_TEXT("DEFAULT_LOGGER"));\
		g_p_defaultLog = &defaultLog;\
		log4cplus::Logger debugLog = getInstance(LOG4CPLUS_TEXT("DEBUG_LOGGER"));\
		g_p_debugLog = &debugLog;\
		log4cplus::Logger sqlLog = getInstance(LOG4CPLUS_TEXT("SQL_LOGGER"));\
		g_p_sqlLog = &sqlLog;\
		}catch (std::exception & e){ std::cout << e.what() << std::endl; return -1; }\
		info_log("log start\n"); }\
		else{ printf("can't find log config"); return -1; }

#define debug_log(format,...) myLog(DEBUG_LOG_LEVEL,g_p_debugLog,"%s:%d|%s <DEBUG>"format,__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__)

#define info_log(format,...) myLog(INFO_LOG_LEVEL,g_p_defaultLog,"%s:%d|%s <INFO>"format,__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__)

#define warn_log(format,...) myLog(WARN_LOG_LEVEL,g_p_defaultLog,"%s:%d|%s <WARN>"format,__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__)
#define err_log(format,...) myLog(ERROR_LOG_LEVEL,g_p_defaultLog,"%s:%d|%s <ERR>"format,__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__)
#define fatal_log(format,...) myLog(FATAL_LOG_LEVEL,g_p_defaultLog,"%s:%d|%s <FATAL>"format,__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__)

#define sql_log(format,...) myLog(WARN_LOG_LEVEL,g_p_sqlLog,"%s:%d|%s <SQL>"format,__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__)


#endif