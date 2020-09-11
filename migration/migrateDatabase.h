#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<sstream>
#include"../config/connectDatabase.h"
using namespace std;

void MigrateAllTable();
void CreateTableEmail();
void CreateTableEmailSent();
void CreateTableEmailInbox();

void MigrateAllTable() {
    CreateTableEmail();
    CreateTableEmailSent();
    CreateTableEmailInbox();
}

void CreateTableEmail() {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        cout << "Fail\n";
        mysql_close(conn);
        return;
    }
    string query =
R"(CREATE TABLE email(
id int NOT NULL AUTO_INCREMENT,
name varchar(255) NOT NULL,
password varchar(255) NOT NULL,
email varchar(255) NOT NULL,
created_at datetime NOT NULL,
last_login datetime NOT NULL,
PRIMARY KEY(id)
)
)";
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        cout << "Create Table Email Success\n";
    }
    else{
        cout << "Create Table Email Fail\n";
    }

    mysql_close(conn);
}

void CreateTableEmailSent() {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        cout << "Fail\n";
        mysql_close(conn);
        return;
    }
    string query =
R"(CREATE TABLE email_sent(
id int NOT NULL AUTO_INCREMENT,
receiver_name varchar(255) NOT NULL,
subject varchar(255) NOT NULL,
description varchar(255) NOT NULL,
available int NOT NULL,
sent_at datetime NOT NULL,
sender_email_id int NOT NULL,
PRIMARY KEY(id)
)
)";
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        cout << "Create Table email_sent Success\n";
    }
    else{
        cout << "Create Table email_sent Fail\n";
    }

    mysql_close(conn);
}

void CreateTableEmailInbox() {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        cout << "Fail\n";
        mysql_close(conn);
        return;
    }
    string query =
R"(CREATE TABLE email_inbox(
id int NOT NULL AUTO_INCREMENT,
sender_name varchar(255) NOT NULL,
subject varchar(255) NOT NULL,
description varchar(255) NOT NULL,
available int NOT NULL,
read_status int NOT NULL,
sent_at datetime NOT NULL,
receiver_email_id int NOT NULL,
PRIMARY KEY(id)
)
)";
    const char *q = query.c_str();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        cout << "Create Table email_inbox Success\n";
    }
    else{
        cout << "Create Table email_inbox Fail\n";
    }

    mysql_close(conn);
}
