#ifndef MODEL_PARAM_EMAIL
#define MODEL_PARAM_EMAIL 1
#include"modelEmailInbox.h"
#include"modelEmailSent.h"

struct Email {
    int id;
    string name;
    string password;
    string email;
    string created_at;
    string last_login;
};

struct NewEmail {
    string name;
    string password;
    string email;
    string created_at;
    string last_login;
};

struct UpdateEmail {
    int id;
    string name;
    string password;
    string email;
    string created_at;
    string last_login;
};

#endif // MODEL_PARAM
