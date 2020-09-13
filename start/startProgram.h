#include<iostream>
#include<windows.h>
#include<conio.h>
#include<mysql.h>
#include"../tools/hasherTools.h"
#include"../config/connectDatabase.h"
#include"../migration/migrateDatabase.h"
#include"../model/modelEmail.h"
#include"../service/serviceEmail.h"
#include"../display/displayEmail.h"

#include<string>

#include <fcntl.h>
#include<stdio.h>

#include<stdlib.h>
#include <ctime>
#include"../tools/hasherTools.h"
using namespace std;


void StartProgram()
{
//    time_t now = time(0);
//    tm *ltm = localtime(&now);
//
//    string temp = to_string(ltm->tm_year + 1900) + "-" + to_string(ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
//
//    struct NewEmail input;
//    input.name = "David Yap";
//    input.password = "12345";
//    input.email = "email@gmail.com";
//    input.created_at = temp;
//    input.last_login = "00-00-00 00:00:00";
//
//    bool flag = ServiceCreateEmail(input);
//
//    if(flag){
//        cout << "Success\n";
//    }
//    else{
//        cout << "Fail\n";
//    }

    EmailMainMenu();

//    _setmode(_fileno(stdout), _O_U16TEXT);
//
//    wprintf(L"\x2665");
//
//    _setmode(_fileno(stdout), _O_TEXT);
}

