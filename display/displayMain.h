#ifndef DISPLAY_MAIN_PARAM
#define DISPLAY_MAIN_PARAM 1

#include<iostream>
#include<string.h>
#include<windows.h>

#include "../tools/cursorTools.h"
#include "../tools/timeTools.h"
#include "displayEmail.h"

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

void DisplayMainWebsite();
void PrintMainWebsiteHeader();

//Global Variable
char websiteSymbol[17][105] = {
"0011111111000000000000000111111000000000000000000000000000000000000000000000000000000000000000000000",//1
"0100111111001111101111100111100100000001111001111000111110000000000000000000000000000000000000000000",//2
"1000100111010000011110010100100100000110111110010101000001000000000000000000000000000000000000000000",//3
"1000011100100111001101101100100111000100111(001110)0010100100000000000000000000000000000000000000000",//4
"011111110011111100(111100111111111011011110011111111111100100000000000000000000000000000000000000000",//5
"0000000011000000110000011000000000011000001100000000000011000000000000000000000000000000000000000000",//6
"2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222",//7
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",//8
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",//9
"00000000000000000000000000LOGIN000000000000000000000000000000000000000000000000000000000000000000000",// (18 19,10) (37 38,10)
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",//11
"0000000000000000000000000REGISTER0000000000000000000000000000000000000000000000000000000000000000000",// (X,12) (X2,12)
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",//13
"00000000000000000000000000RETURN00000000000000000000000000000000000000000000000000000000000000000000",//14
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",//15
"000000000000000000000000000EXIT000000000000000000000000000000000000000000000000000000000000000000000",//16
};


void DisplayMainWebsite(){
    PrintMainWebsiteHeader();

    int option_now = 9;
    int option_max = 15;
    int option_min = 9;

    SetCursorVisible(false);

    websiteSymbol[9][18] = '>';
    websiteSymbol[9][19] = '>';
    websiteSymbol[9][37] = '<';
    websiteSymbol[9][38] = '<';

    websiteSymbol[11][18] = ' ';
    websiteSymbol[11][19] = ' ';
    websiteSymbol[11][37] = ' ';
    websiteSymbol[11][38] = ' ';

    websiteSymbol[13][18] = ' ';
    websiteSymbol[13][19] = ' ';
    websiteSymbol[13][37] = ' ';
    websiteSymbol[13][38] = ' ';

    websiteSymbol[15][18] = ' ';
    websiteSymbol[15][19] = ' ';
    websiteSymbol[15][37] = ' ';
    websiteSymbol[15][38] = ' ';

    #ifndef ONLY_ONCE_WEBSITE_LOGO
    #define ONLY_ONCE_WEBSITE_LOGO 1
        int len_x = strlen(websiteSymbol[0]);

        for(int i = 0; i < 15; i++){
            for(int j = 0; j < len_x; j++){
                if(websiteSymbol[i][j] == '1'){
                    websiteSymbol[i][j] = char(STAGE4);
                }
                else if(websiteSymbol[i][j] == '2'){
                    websiteSymbol[i][j] = char(HORIZON_LINE);
                }
                else if(websiteSymbol[i][j] == '0'){
                    websiteSymbol[i][j] = ' ';
                }
            }
        }
    #endif

    for(int i = 0; i < 17; i++){
        if(i == 7){
            cout << GetTimeNow();
        }
        else{
            cout << websiteSymbol[i];
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
                    websiteSymbol[option_now][18] = ' ';
                    websiteSymbol[option_now][19] = ' ';
                    websiteSymbol[option_now][37] = ' ';
                    websiteSymbol[option_now][38] = ' ';
                    option_now -= 2;
                    websiteSymbol[option_now][18] = '>';
                    websiteSymbol[option_now][19] = '>';
                    websiteSymbol[option_now][37] = '<';
                    websiteSymbol[option_now][38] = '<';
                }

                SetCursorPosition(0,8);
                for(int i = 8; i < 15; i++){
                    cout << websiteSymbol[i] << '\n';
                }
            }
            else if(c == KEY_DOWN){
                if(option_now != option_max){
                    websiteSymbol[option_now][18] = ' ';
                    websiteSymbol[option_now][19] = ' ';
                    websiteSymbol[option_now][37] = ' ';
                    websiteSymbol[option_now][38] = ' ';
                    option_now += 2;
                    websiteSymbol[option_now][18] = '>';
                    websiteSymbol[option_now][19] = '>';
                    websiteSymbol[option_now][37] = '<';
                    websiteSymbol[option_now][38] = '<';
                }

                SetCursorPosition(0,8);
                for(int i = 8; i < 15; i++){
                    cout << websiteSymbol[i] << '\n';
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

void PrintMainWebsiteHeader(){
    system("@cls||clear");

    for(int i = 0; i < 7; i++){
        cout << websiteSymbol[i] << '\n';
    }
}

#endif // DISPLAY_MAIN_PARAM
