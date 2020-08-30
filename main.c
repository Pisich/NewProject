#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Account{
    int number[19];
    char name[100];
    long float balance;
    short typeAcc;
}Account;

typedef struct LoggedUser{
    char user[100];
    char password[100];
    short perms;
}LoggedUser;

void initial_print(){
    system("figlet -c PisiCh Bank");
    printf("What operation would you like to perform?\n");
}


int main(){
    initial_print();
}
