#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Account{
    int number[19];
    char name[100];
    long double balance;
    short typeAcc;
}Account;

typedef struct LoggedUser{
    char user[100];
    char password[100];
    short perms;
}LoggedUser;

void initial_print(){
    //system("figlet -c PisiCh Bank");
    printf("What operation would you like to perform?\n");
    printf("1. Create a new account\n2. Check the balance of your account\n");
    printf("3. Deposit money into your account\n4. Withdraw money from your account\n");
    printf("5. Change any account details\n6. Delete an existing account\n");
    printf("Enter the number of your selection: ");
}


int main(){
    int test = 12;
    int *selection = &test;
    initial_print();
    scanf("%d", selection);

    printf("%d\n", *selection);

}
