#ifndef _LOG_H
#define _LOG_H

#if 0
	#include <android/log.h>
	#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
	#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#else
	#define  LOGD(format, ...)  printf( __FILE__", %d, [DEBUG]:" format"\n", __LINE__, ##__VA_ARGS__)
	#define	 LOGE(format, ...)	printf(__FILE__", %d, [ERROR]:" format"\n", __LINE__, ##__VA_ARGS__)
#endif
#define  ANNOT "stee"

#endif // !_LOG_H

