#ifndef ENVIRONMENT_PARAM
#define ENVIRONMENT_PARAM 1
#include<iostream>
#include<string>
using namespace std;

class Environment{
    public :
        string UserGetIPAddress();
        string UserGetUsername();
        string UserGetPassword();
        string UserGetDatabaseName();
        string UserGetEmailTableName();

    private :
        const string ip_address = "localhost";
        const string username = "root";
        const string password = "";
        const string database_name = "tokomedia_sql";
        const string email_table_name = "email";
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

#endif // ENVIRONMENT_PARAM
