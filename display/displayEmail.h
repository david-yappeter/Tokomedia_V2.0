#ifndef DISPLAY_PARAM_EMAIL
#define DISPLAY_PARAM_EMAIL 1
#include<iostream>
#include<string.h>
#include<windows.h>

#include "../tools/cursorTools.h"
#include "../tools/timeTools.h"

#define STAGE4 219
#define STAGE3 178
#define STAGE2 177
#define STAGE1 176
#define LARGE_DOT 254
#define CORNER1 201
#define CORNER2 187
#define CORNER3 200
#define CORNER4 188
#define HORIZON_LINE 205
#define VERTICAL_LINE 186
#define KEY_UP 72  //arrow keys
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_BACKSPACE 8
using namespace std;

// Email Display Function
void EmailMainMenu();
void EmailLoginMenu();
void EmailRegisterMenu();
void EmailDashboard();
void EmailInboxDescription(struct EmailInbox);
void EmailSent();
void EmailSentDescription(struct EmailSent);
void EmailArchive();

// Misc
void PrintHeader();

// Global Variable
struct Email login_now;
int dashboard_page_now = 1;
int archived_email_inbox_page_now = 1;

char gmailSymbol[15][100] = {
"00111111110000000000000001111110000000000000000000000000000",//1
"01001111110011111011111001111001000000011110011110001111100",//2
"10001001110100000111100101001001000001101111100101010000010",//3
"1000011100100111001101101100100111000100111(001110)00101001",//4
"011111110011111100(1111001111111110110111100111111111111001",//5
"00000000110000001100000110000000000110000011000000000000110",//6
"22222222222222222222222222222222222222222222222222222222222",//7
"00000000000000000000000000000000000000000000000000000000000",//8
"00000000000000000000000000000000000000000000000000000000000",//9
"00000000000000000000000000LOGIN0000000000000000000000000000",// (18 19,10) (37 38,10)
"00000000000000000000000000000000000000000000000000000000000",//11
"0000000000000000000000000REGISTER00000000000000000000000000",// (X,12) (X2,12)
"00000000000000000000000000000000000000000000000000000000000",//13
"00000000000000000000000000RETURN000000000000000000000000000",//14
};

void EmailMainMenu(){
    system("@cls||clear");
    int option_now = 9;
    int option_max = 13;
    int option_min = 9;

    SetCursorVisible(false);

    gmailSymbol[9][18] = '>';
    gmailSymbol[9][19] = '>';
    gmailSymbol[9][37] = '<';
    gmailSymbol[9][38] = '<';

    gmailSymbol[11][18] = ' ';
    gmailSymbol[11][19] = ' ';
    gmailSymbol[11][37] = ' ';
    gmailSymbol[11][38] = ' ';

    gmailSymbol[13][18] = ' ';
    gmailSymbol[13][19] = ' ';
    gmailSymbol[13][37] = ' ';
    gmailSymbol[13][38] = ' ';

    #ifndef ONLY_ONCE
    #define ONLY_ONCE
        int len_x = strlen(gmailSymbol[0]);

        for(int i = 0; i < 15; i++){
            for(int j = 0; j < len_x; j++){
                if(gmailSymbol[i][j] == '1'){
                    gmailSymbol[i][j] = char(STAGE4);
                }
                else if(gmailSymbol[i][j] == '2'){
                    gmailSymbol[i][j] = char(HORIZON_LINE);
                }
                else if(gmailSymbol[i][j] == '0'){
                    gmailSymbol[i][j] = ' ';
                }
            }
        }
    #endif

    for(int i = 0; i < 15; i++){
        if(i == 7){
            cout << GetTimeNow();
        }
        else{
            cout << gmailSymbol[i];
        }
        cout << '\n';
    }

    while(1){

        SetCursorPosition(0,7);
        cout << GetTimeNow();

        if(kbhit()){
            char c = getch();

            if(c == KEY_UP){
                if(option_now != option_min){
                    gmailSymbol[option_now][18] = ' ';
                    gmailSymbol[option_now][19] = ' ';
                    gmailSymbol[option_now][37] = ' ';
                    gmailSymbol[option_now][38] = ' ';
                    option_now -= 2;
                    gmailSymbol[option_now][18] = '>';
                    gmailSymbol[option_now][19] = '>';
                    gmailSymbol[option_now][37] = '<';
                    gmailSymbol[option_now][38] = '<';
                }

                SetCursorPosition(0,8);
                for(int i = 8; i < 15; i++){
                    cout << gmailSymbol[i] << '\n';
                }
            }
            else if(c == KEY_DOWN){
                if(option_now != option_max){
                    gmailSymbol[option_now][18] = ' ';
                    gmailSymbol[option_now][19] = ' ';
                    gmailSymbol[option_now][37] = ' ';
                    gmailSymbol[option_now][38] = ' ';
                    option_now += 2;
                    gmailSymbol[option_now][18] = '>';
                    gmailSymbol[option_now][19] = '>';
                    gmailSymbol[option_now][37] = '<';
                    gmailSymbol[option_now][38] = '<';
                }

                SetCursorPosition(0,8);
                for(int i = 8; i < 15; i++){
                    cout << gmailSymbol[i] << '\n';
                }
            }
            else if(c == KEY_ENTER){
                if(option_now == 9){
                    EmailLoginMenu();
                    break;
                }
                else if(option_now == 11){
                    EmailRegisterMenu();
                    break;
                }
            }

        }

    }

}

void EmailLoginMenu() {
    PrintHeader();

    char temp[255];
    int index = 0;
    int reset_x_default_position = 17;
    int default_position_x = 17;
    int default_position_y = 10;
    int inputan = 1;

    SetCursorPosition(0,10);
    cout << "Enter Email    : ";
    SetCursorPosition(0,11);
    cout << "Enter Password : ";

     while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        cout << ctime(&tempTime);


        SetCursorVisible(true);
        SetCursorPosition(default_position_x,default_position_y);
        if(kbhit()){
            temp[index] = getch();
            if(temp[index] == 13){
		    	if(index == 0){
                    continue;
				}

                if(inputan == 1){
                    temp[index] = '\0';

                    string s(temp);

                    if(s == "0"){
                        cout << "Aborting Operation";
                        getchar();
                        break;
                    }
                    vector<struct Email> AllEmail = ServiceGetEmailAll();

                    int flag = 1;
                    for(auto it : AllEmail){
                        if(ToLower(s) == ToLower(it.email)){
                                login_now = it;
                                flag = 0;
                                break;
                        }
                    }

                    if(flag){
                        SetCursorPosition(0,13);
                        cout << "Email is Not Registered!!!\n";
                        cout << "Press Any Key To Continue\n";
                        while(1){
                            if(kbhit()){
                                break;
                            }
                        }

                        default_position_x = reset_x_default_position;
                        index = 0;
                        SetCursorPosition(default_position_x, 10);
                        for(int i = 0; i < strlen(temp); i++) cout << " ";
                        SetCursorPosition(0, 13);
                        for(int i = 0; i < 30; i++) cout << " ";
                        SetCursorPosition(0, 14);
                        for(int i = 0; i < 30; i++) cout << " ";
                        continue;
                    }

                    inputan++;
                    default_position_y++;
                    default_position_x = reset_x_default_position;
                    index = 0;
                }
                else if(inputan == 2){
                    temp[index] = '\0';

                    string s(temp);

                    if(HasherCompare(s, login_now.password)){
                        break;
                    }
                    else{
                        SetCursorPosition(0,13);
                        cout << "Password Wrong!!!\n";
                        cout << "Press Any Key To Continue\n";
                        while(1){
                            if(kbhit()){
                                break;
                            }
                        }
                        default_position_x = reset_x_default_position;
                        index = 0;
                        SetCursorPosition(default_position_x, 11);
                        for(int i = 0; i < strlen(temp); i++) cout << " ";
                        SetCursorPosition(0, 13);
                        for(int i = 0; i < 30; i++) cout << " ";
                        SetCursorPosition(0, 14);
                        for(int i = 0; i < 30; i++) cout << " ";
                        continue;
                    }

                }
                continue;
			}
			if(temp[index] == 32){
                if(inputan == 1){
                    continue;
                }
				SetCursorPosition(default_position_x, default_position_y);
				if(inputan == 2){
                    cout << "*";
				}
				else{
                    cout << " ";
				}
				index++;
                default_position_x++;
				continue;
			}
			if(temp[index] == 8){
				if(index == 0){
                    continue;
				}
				default_position_x--;
				SetCursorPosition(default_position_x, default_position_y);
				cout << " ";
				index--;
				continue;
			}
			if(((temp[index] >= 'A' && temp[index] <= 'Z') || (temp[index] >= 'a' && temp[index] <= 'z') || (temp[index] >= '0' && temp[index] <= '9') || temp[index] == '@' || temp[index] == '.') == 0){
				continue;
			}

            SetCursorPosition(default_position_x, default_position_y);
            if(inputan == 2){
                cout << "*";
            }
            else{
                cout << temp[index];
            }
		    index++;
            default_position_x++;
        }

        Sleep(50);
    }

    SetCursorPosition(0,13);
    cout << "Success Login\nPress Any Key To Continue\n";

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        cout << ctime(&tempTime);


        if(kbhit()){
            struct UpdateEmail update_email;
            update_email.id = login_now.id;
            update_email.name = login_now.name;
            update_email.password = login_now.password;
            update_email.email = login_now.email;
            update_email.created_at = login_now.created_at;
            update_email.last_login = GetTimeNow();

            ServiceUpdateEmail(update_email);
            getchar();
            EmailDashboard();
            break;
        }
    }

}

void EmailRegisterMenu(){
    PrintHeader();

    struct NewEmail new_email;
    char temp[255];
    int index = 0;
    int reset_x_default_position = 17;
    int default_position_x = 17;
    int default_position_y = 10;
    int inputan = 1;

    SetCursorPosition(0,10);
    cout << "Enter Email    : ";
    SetCursorPosition(0,11);
    cout << "Enter Name     : ";
    SetCursorPosition(0,12);
    cout << "Enter Password : ";

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        cout << ctime(&tempTime);


        SetCursorVisible(true);
        SetCursorPosition(default_position_x,default_position_y);
        if(kbhit()){
            temp[index] = getch();
            if(temp[index] == 13){
		    	if(index == 0){
                    continue;
				}

                if(inputan == 1){
                    temp[index] = '\0';

                    string s(temp);
                    new_email.email = s;

                    if(new_email.email == "0"){
                        SetCursorPosition(0,13);
                        cout << "Aborting Operation";
                        getchar();
                        EmailMainMenu();
                        break;
                    }
                    vector<struct Email> AllEmail = ServiceGetEmailAll();

                    for(auto it : AllEmail){
                        if(ToLower(new_email.email) == ToLower(it.email)){
                                SetCursorPosition(0,13);
                                cout << "Email Exists\n";
                                cout << "Press Enter To Continue";
                                getchar();
                                EmailRegisterMenu();
                        }
                    }

                    inputan++;
                    default_position_y++;
                    default_position_x = reset_x_default_position;
                    index = 0;
                }
                else if(inputan == 2){
                    temp[index] = '\0';

                    string s(temp);
                    new_email.name = s;

                    if(new_email.name == "0"){
                        SetCursorPosition(0,13);
                        cout << "Aborting Operation";
                        getchar();
                        EmailMainMenu();
                        break;
                    }
                    inputan++;
                    default_position_y++;
                    default_position_x = reset_x_default_position;
                    index = 0;
                }
                else if(inputan == 3){
                    temp[index] = '\0';

                    string s(temp);
                    new_email.password = s;
                    break;
                }
                continue;
			}
			if(temp[index] == 32){
                if(inputan == 1){
                    continue;
                }
				SetCursorPosition(default_position_x, default_position_y);
				if(inputan == 3){
                    cout << "*";
				}
				else{
                    cout << " ";
				}
				index++;
                default_position_x++;
				continue;
			}
			if(temp[index] == 8){
				if(index == 0){
                    continue;
				}
				default_position_x--;
				SetCursorPosition(default_position_x, default_position_y);
				cout << " ";
				index--;
				continue;
			}
			if(((temp[index] >= 'A' && temp[index] <= 'Z') || (temp[index] >= 'a' && temp[index] <= 'z') || (temp[index] >= '0' && temp[index] <= '9') || temp[index] == '@' || temp[index] == '.') == 0){
				continue;
			}

            SetCursorPosition(default_position_x, default_position_y);
            if(inputan == 3){
                cout << "*";
            }
            else{
                cout << temp[index];
            }
		    index++;
            default_position_x++;
        }

        Sleep(50);
    }

    new_email.created_at = GetTimeNow();
    new_email.last_login = GetTimeZero();

    bool flag = ServiceCreateEmail(new_email);

    SetCursorPosition(0,13);
    if(flag){
        cout << "Success\n";
    }
    else{
        cout << "Fail\n";
    }
    cout << "Press Any Key To Continue\n";

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        cout << ctime(&tempTime);

        if(kbhit()){
            EmailMainMenu();
        }
    }

}

void EmailDashboard() {
    PrintHeader();

    SetCursorPosition(0,8);
    cout << "Welcome, " << login_now.name << '\n';
    for(int i = 0; i < 59; i++) cout << char(HORIZON_LINE);

    vector<struct EmailInbox> email_inbox = ServiceGetEmailInboxByUserID(login_now.id);

    int size_email_inbox = email_inbox.size();
    string email_inbox_counter = to_string(size_email_inbox);

    string email_count_text = email_inbox_counter + " Email";
    if(size_email_inbox > 1){
        email_count_text += "s";
    }
    email_count_text += " In Your Inbox";

    int count_temp_pos = 58;
    for(int i = email_count_text.length() - 1; i >= 0; i--){
        SetCursorPosition(count_temp_pos, 8);
        cout << email_count_text[i];
        count_temp_pos--;
    }

    int max_pagination_page;
    if(size_email_inbox % 15 == 0){
        max_pagination_page = size_email_inbox / 15;
    }
    else{
        max_pagination_page = size_email_inbox / 15 + 1;
    }

    SetCursorPosition(7,10);
    cout << "Sender\tSubject\t\t\tSent At";

    SetCursorPosition(0, 11);
    for(int i = 0; i < 59; i++) cout << char(HORIZON_LINE);

    int inbox_y = 12;
    int temp_y = inbox_y;

    for(int i = inbox_y; i < temp_y + size_email_inbox; i++){
        SetCursorPosition(5,inbox_y);
        if(email_inbox[i - temp_y].read_status == 2){
            cout << char(254) << " ";
        }
        else{
            cout << "  ";
        }
        cout << email_inbox[i - temp_y].sender_name << '\t' << email_inbox[i - temp_y].subject << "\t\t" << email_inbox[i - temp_y].sent_at << '\n';
        inbox_y++;
    }

    SetCursorPosition(0, inbox_y + 1);
    for(int i = 0; i < 59; i++) cout << char(HORIZON_LINE);
    SetCursorPosition(27, inbox_y + 2);
    cout << dashboard_page_now << "/" << max_pagination_page;

    int selected_email_inbox;
    int range_min, range_max;
    int flag = 0;
    if(size_email_inbox > 0){
        selected_email_inbox = (dashboard_page_now - 1) * 15 + 1;
        SetCursorPosition(2, temp_y);
        cout << ">>";

        range_min = (dashboard_page_now - 1) * 15 + 1;
        if(dashboard_page_now != max_pagination_page){
            range_max = range_min + 14;
        }
        else{
            range_max = size_email_inbox;
        }
        flag = 1;
    }
    else{
        selected_email_inbox = 0;
        SetCursorPosition(5, temp_y);
        cout << "Inbox Empty";
    }

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        cout << ctime(&tempTime);

        if(kbhit()){
            char c = getch();

            if(flag){
                if(c == KEY_ENTER){
                    EmailInboxDescription(email_inbox[selected_email_inbox - 1]);
                }
                else if(c == KEY_UP){
                    if(selected_email_inbox == range_min){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    cout << "  ";
                    temp_y--;
                    selected_email_inbox--;
                    SetCursorPosition(2, temp_y);
                    cout << ">>";
                }
                else if(c == KEY_DOWN){
                    if(selected_email_inbox == range_max){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    cout << "  ";
                    temp_y++;
                    selected_email_inbox++;
                    SetCursorPosition(2, temp_y);
                    cout << ">>";
                }
                else if(c == KEY_LEFT){
                    if(dashboard_page_now == 1){
                        continue;
                    }
                    dashboard_page_now--;
                    EmailDashboard();
                }
                else if(c == KEY_RIGHT){
                    if(dashboard_page_now == max_pagination_page){
                        continue;
                    }
                    dashboard_page_now++;
                    EmailDashboard();
                }
                else if(c == 'A' || c == 'a'){
                    EmailArchive();
                }
                else if(c == 'R' || c == 'r'){
                    struct UpdateEmailInbox update_email_inbox;
                    update_email_inbox.id = email_inbox[selected_email_inbox - 1].id;
                    update_email_inbox.sender_name = email_inbox[selected_email_inbox - 1].sender_name;
                    update_email_inbox.subject = email_inbox[selected_email_inbox - 1].subject;
                    update_email_inbox.description = email_inbox[selected_email_inbox - 1].description;
                    update_email_inbox.available = 2;
                    update_email_inbox.read_status = email_inbox[selected_email_inbox - 1].read_status;
                    update_email_inbox.sent_at = email_inbox[selected_email_inbox - 1].sent_at;
                    update_email_inbox.receiver_email_id = email_inbox[selected_email_inbox - 1].receiver_email_id;
                    ServiceUpdateEmailInbox(update_email_inbox);
                    EmailDashboard();
                }
            }
            else{
                if(c == 'A' || c == 'a'){
                    EmailArchive();
                }
                else if(c == '0' || c == KEY_BACKSPACE){
                    system("@cls||clear");
                    cout << "Logging Out . . . .\n";
                    cout << "Press Any Enter To Continue\n";
                    getchar();
                    dashboard_page_now = 1;
                    archived_email_inbox_page_now = 1;
                    EmailMainMenu();
                }
            }
        }
    }


}

void EmailInboxDescription(struct EmailInbox input) {
    PrintHeader();

    struct UpdateEmailInbox update_email_inbox;
    update_email_inbox.id = input.id;
    update_email_inbox.description = input.description;
    update_email_inbox.receiver_email_id = input.receiver_email_id;
    update_email_inbox.sender_name = input.sender_name;
    update_email_inbox.sent_at = input.sent_at;
    update_email_inbox.subject = input.subject;
    update_email_inbox.available = input.available;
    update_email_inbox.read_status = 1;

    SetCursorPosition(20,20);
    cout << ServiceUpdateEmailInbox(update_email_inbox);

    SetCursorPosition(0,8);
    cout << "Sender : " << input.sender_name << " at " << input.sent_at << '\n';
    for(int i = 0; i < 59; i++) cout << char(HORIZON_LINE);
    cout << "\nSubject : " << input.subject << "\n\n";
    cout << input.description << '\n';
    for(int i = 0; i < 59; i++) cout << char(HORIZON_LINE);

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        cout << ctime(&tempTime);

        if(kbhit()){
            char c = getch();

            if(c == KEY_BACKSPACE || c == '0'){
                EmailDashboard();
                break;
            }
        }
    }
}

void EmailArchive() {
    PrintHeader();

    vector<struct EmailInbox> archived_email  = ServiceGetArchivedEmailInboxByUserID(login_now.id);
    int archived_count = archived_email.size();

    SetCursorPosition(0,8);
    cout << "You have " << archived_count << " Archived Email(s)"<< '\n';
    for(int i = 0; i < 59; i++) cout << char(HORIZON_LINE);

    SetCursorPosition(7,10);
    cout << "Sender\tSubject\t\t\tSent At";

    SetCursorPosition(0, 11);
    for(int i = 0; i < 59; i++) cout << char(HORIZON_LINE);

    int inbox_y = 12;
    int temp_y = inbox_y;

    int max_pagination_page;
    if(archived_count % 15 == 0){
        max_pagination_page = archived_count / 15;
    }
    else{
        max_pagination_page = archived_count / 15 + 1;
    }

    for(int i = inbox_y; i < temp_y + archived_count; i++){
        SetCursorPosition(5,inbox_y);
        cout << "  ";
        cout << archived_email[i - temp_y].sender_name << '\t' << archived_email[i - temp_y].subject << "\t\t" << archived_email[i - temp_y].sent_at << '\n';
        inbox_y++;
    }

    SetCursorPosition(0, inbox_y + 1);
    for(int i = 0; i < 59; i++) cout << char(HORIZON_LINE);
    SetCursorPosition(27, inbox_y + 2);
    cout << archived_email_inbox_page_now << "/" << max_pagination_page;

    int selected_archived_email;
    int range_min, range_max;
    int flag = 0;
    if(archived_count > 0){
        selected_archived_email = (archived_email_inbox_page_now - 1) * 15 + 1;
        SetCursorPosition(2, temp_y);
        cout << ">>";

        range_min = (archived_email_inbox_page_now - 1) * 15 + 1;
        if(archived_email_inbox_page_now != max_pagination_page){
            range_max = range_min + 14;
        }
        else{
            range_max = archived_count;
        }
        flag = 1;
    }
    else{
        selected_archived_email = 0;
        SetCursorPosition(5, temp_y);
        cout << "Inbox Empty";
    }

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        cout << ctime(&tempTime);

        if(kbhit()){
            char c = getch();

            if(flag){
                if(c == 'R' || c == 'r'){
                    struct UpdateEmailInbox update_email_inbox;
                    update_email_inbox.id = archived_email[selected_archived_email - 1].id;
                    update_email_inbox.sender_name = archived_email[selected_archived_email - 1].sender_name;
                    update_email_inbox.subject = archived_email[selected_archived_email - 1].subject;
                    update_email_inbox.description = archived_email[selected_archived_email - 1].description;
                    update_email_inbox.available = 1;
                    update_email_inbox.read_status = archived_email[selected_archived_email - 1].read_status;
                    update_email_inbox.sent_at = archived_email[selected_archived_email - 1].sent_at;
                    update_email_inbox.receiver_email_id = archived_email[selected_archived_email - 1].receiver_email_id;
                    ServiceUpdateEmailInbox(update_email_inbox);
                    EmailArchive();
                }
                else if(c == 'D' || c == 'd'){
                    ServiceDeleteEmailInbox(archived_email[selected_archived_email - 1].id);
                    EmailArchive();
                }
                else if(c == KEY_UP){
                    if(selected_archived_email == range_min){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    cout << "  ";
                    temp_y--;
                    selected_archived_email--;
                    SetCursorPosition(2, temp_y);
                    cout << ">>";
                }
                else if(c == KEY_DOWN){
                    if(selected_archived_email == range_max){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    cout << "  ";
                    temp_y++;
                    selected_archived_email++;
                    SetCursorPosition(2, temp_y);
                    cout << ">>";
                }
                else if(c == KEY_LEFT){
                    if(dashboard_page_now == 1){
                        continue;
                    }
                    dashboard_page_now--;
                    EmailDashboard();
                }
                else if(c == KEY_RIGHT){
                    if(dashboard_page_now == max_pagination_page){
                        continue;
                    }
                    dashboard_page_now++;
                    EmailDashboard();
                }
                else if(c == '0' || c == KEY_BACKSPACE){
                    EmailDashboard();
                    break;
                }
            }
            else{
                if(c == '0' || c == KEY_BACKSPACE){
                    EmailDashboard();
                    break;
                }
            }
        }

    }


}

void PrintHeader(){
    system("@cls||clear");

    for(int i = 0; i < 7; i++){
        cout << gmailSymbol[i] << '\n';
    }
}

#endif // DISPLAY_PARAM
