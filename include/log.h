#pragma once
#ifdef __ANDROID__

#include <android/log.h>
#define APP_NAME "gl2es" // gl2.1
#define DLOG(...) __android_log_print(ANDROID_LOG_DEBUG,   APP_NAME, __VA_ARGS__)
#define ILOG(...) __android_log_print(ANDROID_LOG_INFO,    APP_NAME, __VA_ARGS__)
#define ELOG(...) __android_log_print(ANDROID_LOG_ERROR,   APP_NAME, __VA_ARGS__)
#define VLOG(...) __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, __VA_ARGS__)
#define FLOG(...) __android_log_print(ANDROID_LOG_FATAL,   APP_NAME, __VA_ARGS__)

#else

#include <stdio.h>
#define DLOG(...) fprintf(stdout, __VA_ARGS__)
#define ILOG(...) fprintf(stdout, __VA_ARGS__)
#define ELOG(...) fprintf(stderr, __VA_ARGS__)
#define VLOG(...) fprintf(stdout, __VA_ARGS__)
#define FLOG(...) fprintf(stderr, __VA_ARGS__)
#endif