#ifndef TIME_TOOLS_PARAM
#define TIME_TOOLS_PARAM 1
#include<iostream>
#include<time.h>
#include<string>

#include "hasherTools.h"
#include "descriptionConverter.h"
#include "cursorTools.h"
using namespace std;

string GetTimeNow(){
//    time_t current_time;
//    time(&current_time);
//    return ctime(&current_time);
    time_t now = time(0);
    tm *ltm = localtime(&now);

    string temp = to_string(ltm->tm_year + 1900) + "-" + to_string(ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    return temp;
}

string GetTimeZero(){
    return "00-00-00 00:00:00";
}

#endif // TIME_TOOLS_PARAM
