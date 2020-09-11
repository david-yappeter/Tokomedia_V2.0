#ifndef SERVICE_PARAM_EMAIL
#define SERVICE_PARAM_EMAIL 1
#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<sstream>
#include"../env.h"
#include"../config/connectDatabase.h"
#include"../model/modelEmail.h"
using namespace std;

bool ServiceCreateEmail(struct NewEmail input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        return false;
    }

    Environment env;
    stringstream ss;

    ss << "INSERT INTO " << env.UserGetEmailTableName(); << "(name, password, email, created_at, last_login) VALUES ('" << input.name "', '" << input.password << "', '" << input.email << "', '" << input.created_at << "', '" << input.last_login << "');";

    string query = ss.str();
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        return true;
    }
    else{
        return false;
    }
}

#endif // SERVICE_PARAM
