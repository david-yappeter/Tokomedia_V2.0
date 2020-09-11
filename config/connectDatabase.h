#ifndef CONFIG_PARAM
#define CONFIG_PARAM 1
#include<iostream>
#include<windows.h>
#include<mysql.h>
#include"../env.h"
using namespace std;

MYSQL* ConnectDatabase(){
    MYSQL *conn;
    Environment env;

    conn = mysql_init(0);
    string ip_address, username, pass, database;
    ip_address = env.UserGetIPAddress();
    username = env.UserGetUsername();
    pass = env.UserGetPassword();
    database = env.UserGetDatabaseName();

    conn = mysql_real_connect(conn, ip_address.c_str(), username.c_str(), pass.c_str(), database.c_str(), 0, NULL, 0);

    return conn;
}

#endif // CONFIG_PARAM
