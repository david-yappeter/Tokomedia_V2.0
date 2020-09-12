#ifndef TOOLS_PARAM
#define TOOLS_PARAM 1
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include"sha256.h"
#include"../env.h"
using namespace std;
string sha256Hashing(string word) {
    srand(time(0));
    char arr[55] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    int index = rand() % 52;

    Environment env;
    SHA256 sha256;

    return sha256(arr[index] + word + env.UserGetSalt());
}
#endif // TOOLS_PARAM
