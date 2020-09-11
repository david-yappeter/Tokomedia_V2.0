#ifndef MODEL_PARAM_EMAIL_INBOX
#define MODEL_PARAM_EMAIL_INBOX 1
#include"modelEmail.h"
#include"modelEmailSent.h"

struct EmailInbox {
    int id;
    string sender_name;
    string subject;
    string description;
    int available;
    int read_status;
    string sent_at;
    int receiver_email_id;
};

struct NewEmailInbox {
    string sender_name;
    string subject;
    string description;
    int available;
    int read_status;
    string sent_at;
    int receiver_email_id;
};

struct UpdateEmailInbox {
    int id;
    string sender_name;
    string subject;
    string description;
    int available;
    int read_status;
    string sent_at;
    int receiver_email_id;
};

#endif // MODEL_PARAM
