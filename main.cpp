#include<iostream>
#include<windows.h>
#include<mysql.h>
#include"tools/hasherTools.h"
#include"config/connectDatabase.h"
#include"migration/migrateDatabase.h"
#include"service/serviceEmail.h"

#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
////  MigrateDatabase Table(declare Database Name First)
//    MigrateAllTable();

//    testest();
//    testest();

    srand(time(0));

    cout << rand() % 2 << '\n';

    return 0;
}
