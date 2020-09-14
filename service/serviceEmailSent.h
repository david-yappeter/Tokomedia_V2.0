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
#include"serviceEmailInbox.h"
using namespace std;

bool ServiceCreateEmailSent(struct NewEmailSent input);
bool ServiceUpdateEmailSent(struct UpdateEmailSent input);
bool ServiceDeleteEmailSent(int id);
vector<struct EmailSent> ServiceGetEmailSentByID(int id);
vector<struct EmailSent> ServiceGetEmailSentByUserID(int user_id);
vector<struct EmailSent> ServiceGetArchivedEmailSentByUserID(int user_id);
vector<struct EmailSent> ServiceGetEmailSentAll();

bool ServiceCreateEmailSent(struct NewEmailSent input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    stringstream ss;

    ss << "INSERT INTO " << env.UserGetEmailSentTableName() << " (receiver_name, subject, description, available, sent_at, sender_email_id) VALUES ('" << input.receiver_name << "', '" << input.subject << "', '" << input.description << "', '" << input.available << "', '" << input.sent_at << "', '" << input.sender_email_id << "');";

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

    ss << "UPDATE " << env.UserGetEmailSentTableName() << " SET receiver_name = '" << input.receiver_name << "', subject = '" << input.subject << "', description = '" << input.description << "', available = '" << input.available << "', sent_at = '" << input.sent_at << "', sender_email_id = '" << input.sender_email_id << "' WHERE id = " << input.id << ";";

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

    ss << "DELETE FROM " << env.UserGetEmailSentTableName() << " WHERE id = " << id << ";";

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

vector<struct EmailSent> ServiceGetEmailSentByID(int id){
    MYSQL *conn = ConnectDatabase();
    vector<struct EmailSent> email_sent;

    if(!conn){
        mysql_close(conn);
        return email_sent;
    }

    Environment env;
    stringstream ss;

    ss << "SELECT * FROM " << env.UserGetEmailSentTableName() << " WHERE id = " << id << ";";

    string query = ss.str();
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct EmailSent temp;
            temp.id = atoi(row[0]);
            temp.receiver_name = row[1];
            temp.subject = row[2];
            temp.description = row[3];
            temp.available = atoi(row[4]);
            temp.sent_at = row[5];
            temp.sender_email_id = atoi(row[6]);

            email_sent.push_back(temp);
        }

        mysql_close(conn);
        return email_sent;
    }
    else{
        mysql_close(conn);
        return email_sent;
    }
}

vector<struct EmailSent> ServiceGetEmailSentByUserID(int user_id){
    MYSQL *conn = ConnectDatabase();
    vector<struct EmailSent> email_sent;

    if(!conn){
        mysql_close(conn);
        return email_sent;
    }

    Environment env;
    stringstream ss;

    ss << "SELECT * FROM " << env.UserGetEmailSentTableName() << " WHERE sender_email_id = " << user_id << " AND available = '1' ORDER BY sent_at DESC;";

    string query = ss.str();
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct EmailSent temp;
            temp.id = atoi(row[0]);
            temp.receiver_name = row[1];
            temp.subject = row[2];
            temp.description = row[3];
            temp.available = atoi(row[4]);
            temp.sent_at = row[5];
            temp.sender_email_id = atoi(row[6]);

            email_sent.push_back(temp);
        }

        mysql_close(conn);
        return email_sent;
    }
    else{
        mysql_close(conn);
        return email_sent;
    }
}

vector<struct EmailSent> ServiceGetArchivedEmailSentByUserID(int user_id){
    MYSQL *conn = ConnectDatabase();
    vector<struct EmailSent> email_sent;

    if(!conn){
        mysql_close(conn);
        return email_sent;
    }

    Environment env;
    stringstream ss;

    ss << "SELECT * FROM " << env.UserGetEmailSentTableName() << " WHERE sender_email_id = " << user_id << " AND available = '2' ORDER BY sent_at DESC;";

    string query = ss.str();
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct EmailSent temp;
            temp.id = atoi(row[0]);
            temp.receiver_name = row[1];
            temp.subject = row[2];
            temp.description = row[3];
            temp.available = atoi(row[4]);
            temp.sent_at = row[5];
            temp.sender_email_id = atoi(row[6]);

            email_sent.push_back(temp);
        }

        mysql_close(conn);
        return email_sent;
    }
    else{
        mysql_close(conn);
        return email_sent;
    }
}

vector<struct EmailSent> ServiceGetEmailSentAll(){
    MYSQL *conn = ConnectDatabase();
    vector<struct EmailSent> email_sent;

    if(!conn){
        mysql_close(conn);
        return email_sent;
    }

    Environment env;
    stringstream ss;

    ss << "SELECT * FROM " << env.UserGetEmailSentTableName() << ";";

    string query = ss.str();
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct EmailSent temp;
            temp.id = atoi(row[0]);
            temp.receiver_name = row[1];
            temp.subject = row[2];
            temp.description = row[3];
            temp.available = atoi(row[4]);
            temp.sent_at = row[5];
            temp.sender_email_id = atoi(row[6]);

            email_sent.push_back(temp);
        }

        mysql_close(conn);
        return email_sent;
    }
    else{
        mysql_close(conn);
        return email_sent;
    }
}

#endif // SERVICE_PARAM_EMAIL
