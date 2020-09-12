#ifndef ENVIRONMENT_PARAM
#define ENVIRONMENT_PARAM 1
#include<iostream>
#include<string>
//#include<stdio.h>
using namespace std;

class Environment{
    public :
        string UserGetIPAddress();
        string UserGetUsername();
        string UserGetPassword();
        string UserGetDatabaseName();
        string UserGetEmailTableName();
        string UserGetEmailInboxTableName();
        string UserGetEmailSentTableName();

        string UserGetSalt();

    private :
        const string salt = "saltThisThlngs";

        const string ip_address = "localhost";
        const string username = "root";
        const string password = "";
        const string database_name = "tokomedia_sql";
        const string email_table_name = "email";
        const string email_inbox_table_name = "email_inbox";
        const string email_sent_table_name = "email_sent";
};

string Environment::UserGetIPAddress() {
    return ip_address;
}

string Environment::UserGetUsername() {
    return username;
}

string Environment::UserGetPassword() {
    return password;
}

string Environment::UserGetDatabaseName() {
    return database_name;
}

string Environment::UserGetEmailTableName() {
    return email_table_name;
}

string Environment::UserGetEmailInboxTableName() {
    return email_inbox_table_name;
}

string Environment::UserGetEmailSentTableName() {
    return email_sent_table_name;
}

string Environment::UserGetSalt() {
    return salt;
}

#endif // ENVIRONMENT_PARAM
