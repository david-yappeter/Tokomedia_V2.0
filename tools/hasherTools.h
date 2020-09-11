#ifndef TOOLS_PARAM
#define TOOLS_PARAM 1
#include<iostream>
#include"sha256.h"
using namespace std;
string Hasher(string word) {
    SHA256 sha256;
    return sha256(word);
}
#endif // TOOLS_PARAM
