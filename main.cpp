#include<iostream>
#include<windows.h>
#include<mysql.h>
#include"tools/sha256.h"
//#include"config/connectDatabase.h"
using namespace std;

int main()
{
//    MYSQL* conn = ConnectDatabase();
//
//    if(conn){
//        cout << "Success\n";
//    }
//    else{
//        cout << "Fail\n";
//    }

    SHA256 sha256;


    cout << sha256("greijgioueigj9549t894irt943ui90bt84903qt90b9q3nt9b348nt98439btn349nb348b9n34890btn9348t90834n9bt43") << '\n';
    cout << sha256("a").length() << '\n';
    cout << sha256("ababadbab").length() << '\n';


    return 0;
}
