#ifndef SERVICE_PARAM_EMAIL_SENT
#define SERVICE_PARAM_EMAIL_SENT 1
#include<iostream>
#include<sstream>
#include<windows.h>
#include<mysql.h>
#include"../env.h"
#include"../config/connectDatabase.h"
#include"../model/modelEmail.h"
#include"serviceEmail.h"
using namespace std;

bool ServiceCreateEmailSent(struct NewEmailSent input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    stringstream ss;

    ss << "INSERT INTO " << env.UserGetEmailSentTableName() << " (name, receiver_name, subject, description, available, sent_at, sender_email_id) VALUES ('" << input.name << "', '" << input.receiver_name << "', '" << input.subject << "', '" << input.description << "', '" << input.available << "', '" << input.sent_at << "', '" << input.sender_email_id << "');";

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

bool ServiceUpdateEmailSent(struct UpdateEmailSent input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    stringstream ss;

    ss << "UPDATE " << env.UserGetEmailSentTableName() << " SET name = '" << input.name << "', receiver_name = '" << input.receiver_name << "', subject = '" << input.subject << "', description = '" << input.description << "', available = " << input.available << "', sent_at = '" << input.sent_at << "', sender_email_id = " << input.sender_email_id << "' WHERE id = " << input.id << ";";

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

bool ServiceDeleteEmailSent(int id) {
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

#endif // SERVICE_PARAM_EMAIL
