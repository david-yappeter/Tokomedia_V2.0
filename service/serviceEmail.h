#ifndef SERVICE_PARAM_EMAIL
#define SERVICE_PARAM_EMAIL 1
#include<iostream>
#include<sstream>
#include<windows.h>
#include<mysql.h>
#include<vector>
#include"serviceEmailSent.h"
#include"../env.h"
#include"../config/connectDatabase.h"
#include"../model/modelEmail.h"
#include"../tools/hasherTools.h"
using namespace std;

bool ServiceCreateEmail();
bool ServiceUpdateEmail();
bool ServiceDeleteEmail();

bool ServiceCreateEmail(struct NewEmail input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    stringstream ss;

    input.email = ToLower(input.email);

    input.password = sha256Hashing(input.password);

    ss << "INSERT INTO " << env.UserGetEmailTableName() << " (name, password, email, created_at, last_login) VALUES ('" << input.name <<  "', '" << input.password << "', '" << input.email << "', '" << input.created_at << "', '" << input.last_login << "');";

    string query = ss.str();
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    mysql_close(conn);
    if(!q_state){
        return true;
    }
    else{
        return false;
    }
}

bool ServiceUpdateEmail(struct UpdateEmail input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    stringstream ss;

    ss << "UPDATE " << env.UserGetEmailTableName() << " SET name = '" << input.name << "', password = '" << input.password << "', email = '" << input.email << "', created_at = '" << input.created_at << "', last_login = '" << input.last_login << "' WHERE id = " << input.id << ";";

    string query = ss.str();
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    mysql_close(conn);
    if(!q_state){
        return true;
    }
    else{
        return false;
    }
}

bool ServiceDeleteEmail(int id) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    stringstream ss;

    ss << "DELETE FROM " << env.UserGetEmailTableName() << " WHERE id = " << id << ";";

    string query = ss.str();
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    mysql_close(conn);
    if(!q_state){
        return true;
    }
    else{
        return false;
    }
}

vector<struct Email> ServiceGetEmailByID(int id) {
    MYSQL *conn = ConnectDatabase();
    vector<struct Email> temp;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;
    stringstream ss;

    ss << "SELECT * FROM " << env.UserGetEmailTableName() << " WHERE id = " << id << ";";

    string query = ss.str();
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct Email emailTemp;
            emailTemp.id = atoi(row[0]);
            emailTemp.name = row[1];
            emailTemp.password = row[2];
            emailTemp.email = row[3];
            emailTemp.created_at = row[4];
            emailTemp.last_login = row[5];

            temp.push_back(emailTemp);
        }

        mysql_close(conn);
        return temp;
    }
    else{
        mysql_close(conn);
        return temp;
    }
}

vector<struct Email> ServiceGetEmailByEmail(string email){
    MYSQL *conn = ConnectDatabase();
    vector<struct Email> temp;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;
    stringstream ss;

    ss << "SELECT * FROM " << env.UserGetEmailTableName() << " WHERE email = '" << email << "';";

    string query = ss.str();
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct Email emailTemp;
            emailTemp.id = atoi(row[0]);
            emailTemp.name = row[1];
            emailTemp.password = row[2];
            emailTemp.email = row[3];
            emailTemp.created_at = row[4];
            emailTemp.last_login = row[5];

            temp.push_back(emailTemp);
        }

        mysql_close(conn);
        return temp;
    }
    else{
        mysql_close(conn);
        return temp;
    }
}

vector<struct Email> ServiceGetEmailAll() {
    MYSQL *conn = ConnectDatabase();
    vector<struct Email> temp;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;
    stringstream ss;

    ss << "SELECT * FROM " << env.UserGetEmailTableName() << ";";

    string query = ss.str();
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct Email emailTemp;
            emailTemp.id = atoi(row[0]);
            emailTemp.name = row[1];
            emailTemp.password = row[2];
            emailTemp.email = row[3];
            emailTemp.created_at = row[4];
            emailTemp.last_login = row[5];

            temp.push_back(emailTemp);
        }

        mysql_close(conn);
        return temp;
    }
    else{
        mysql_close(conn);
        return temp;
    }
}

#endif // SERVICE_PARAM
