#ifndef MODEL_PARAM_EMAIL_SENT
#define MODEL_PARAM_EMAIL_SENT 1
#include"modelEmail.h"
#include"modelEmailInbox.h"

struct EmailSent {
    int id;
    string receiver_name;
    string subject;
    string description;
    int available;
    string sent_at;
    int sender_email_id;
};

struct NewEmailSent {
    string receiver_name;
    string subject;
    string description;
    int available;
    string sent_at;
    int sender_email_id;
};

struct UpdateEmailSent {
    int id;
    string receiver_name;
    string subject;
    string description;
    int available;
    string sent_at;
    int sender_email_id;
};

#endif // MODEL_PARAM
