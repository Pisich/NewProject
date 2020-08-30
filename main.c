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
void create_acc(){
  printf("create acc\n");
}

void check_bal(){
  printf("check bal\n");
}

void deposit(){
  printf("deposit\n");
}

void withdraw(){
  printf("withdraw\n");
}

void change_details(){
  printf("change det\n");
}

void delete_acc(){
  printf("del acc\n");
}

int main(){
    int test = 12;
    int *selection = &test;
    initial_print();
    scanf("%d", selection);
    while(*selection >= 7 || *selection <= 0){
      printf("Invalid selection, enter a valid operation: ");
      scanf("%d", selection);
    }
    if(*selection == 1)
      create_acc();
    else if(*selection == 2)
      check_bal();
    else if(*selection == 3)
      deposit();
    else if(*selection == 4)
      withdraw();
    else if(*selection == 5)
      change_details();
    else if(*selection == 6)
      delete_acc();
}
