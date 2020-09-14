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

//    string temp = GetTimeNow();

//    struct NewEmailInbox a;
//    a.available = 1;
//    a.description = "sakofjreiwgj asdfi aifkjeiwfwfj";
//    a.read_status = 2;
//    a.receiver_email_id = 1;
//    a.sender_name = "Tester";
//    a.sent_at = temp;
//    a.subject = "Testing 2";
//
//    cout << ServiceCreateEmailInbox(a) << '\n';

//    struct NewEmailSent b;
//
//    b.available = 1;
//    b.description = "sakofjreiwgj asdfi aifkjeiwfwfj";
//    b.receiver_name = "David Yap";
//    b.sender_email_id = 2;
//    b.sent_at = temp;
//    b.subject = "Testing 2";
//
//    cout << ServiceCreateEmailSent(b) << '\n';

//    _setmode(_fileno(stdout), _O_U16TEXT);
//
//    wprintf(L"\x2665");
//
//    _setmode(_fileno(stdout), _O_TEXT);
}

