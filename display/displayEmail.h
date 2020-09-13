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
using namespace std;

// Email Display Function
void EmailMainMenu();
void EmailLoginMenu();
void EmailRegisterMenu();
void EmailDashboard();
void EmailInbox();
void EmailSent();
void EmailArchive();
void EmailDesc();

// Misc
void PrintHeader();

// Global Variable
struct Email login_now;

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
				SetCursorPosition(default_position_x, default_position_y);
                cout << " ";
				index++;
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
            // MAIN MENU
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
				SetCursorPosition(default_position_x, default_position_y);
                cout << " ";
				index++;
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

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        cout << ctime(&tempTime);

    }


}

void PrintHeader(){
    system("@cls||clear");

    for(int i = 0; i < 7; i++){
        cout << gmailSymbol[i] << '\n';
    }
}

#endif // DISPLAY_PARAM
