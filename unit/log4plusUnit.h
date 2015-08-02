#ifndef LOG4CPLUS_UNIT_H
#define LOG4CPLUS_UNIT_H

#include <log4cplus/configurator.h>
#include <log4cplus/logger.h>
#include <log4cplus/loglevel.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <stdio.h>


    inline int logStart(const char* p_configFile)
	{
		log4cplus::initialize();
		try
		{
			log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(p_configFile));
		}
		catch(std::exception const & e) 
		{
			std::cout << e.what() << std::endl;
			return -1;
		}
		return 0;
	}

	inline log4cplus::Logger getInstance(const char* i_pLogger)
	{
		return log4cplus::Logger::getInstance( i_pLogger);
	}

	inline void myLog(log4cplus::LogLevel logLevel, log4cplus::Logger* p_log, const char* p_format, ...)
	{
		    char szBuf[10240];
			va_list paramList;
			va_start(paramList,p_format);
#ifdef WIN32
			vsnprintf_s(szBuf,sizeof(szBuf),_TRUNCATE,p_format,paramList);
#else
			vsnprintf(szBuf,sizeof(szBuf),p_format,paramList);
#endif
			va_end(paramList);
		if(p_log!=NULL)
		{
			if ( p_log->isEnabledFor(logLevel) )
			{
				p_log->forcedLog(logLevel, szBuf);
			}
		}else
		{
			printf(p_format,szBuf);
		}
	}


#endif