#ifndef HASHER_TOOLS_PARAM
#define HASHER_TOOLS_PARAM 1
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string>
#include"sha256.h"
#include"../env.h"

#include "cursorTools.h"
#include "timeTools.h"

using namespace std;

string sha256Hashing(string word) {
    srand(time(0));
    string arr = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    int index = rand() % 52;

    Environment env;
    SHA256 sha256;

    return sha256(arr[index] + word + env.UserGetSalt());
}

bool HasherCompare(string pass, string hashedPassword) {
    SHA256 sha256;
    string arr = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    Environment env;

    cout << '\n';
    bool flag = false;
    for(int i = 0; i < 52; i++){
        string temp = sha256(arr[i] + pass + env.UserGetSalt());

        if(temp == hashedPassword){
            flag = true;
            break;
        }
    }

    return flag;
}

string ToLower(string word) {
    int word_len = word.length();
    for(int i = 0; i < word_len; i++){
        if(word[i] >= 'A' && word[i] <= 'Z'){
            word[i] += 32;
        }
    }

    return word;
}

#endif // TOOLS_PARAM

