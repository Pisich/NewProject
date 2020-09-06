#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_NAME_LEN 100
#define MAX_PASS_LEN 50

typedef struct Account{
  int number[16];
  char name[MAX_NAME_LEN];
  long int balance;
  short typeAcc;
  int PIN;
}Account;

typedef struct LoggedUser{
  char user[MAX_NAME_LEN];
  char password[MAX_PASS_LEN];
  short perms;
  int details;
}LoggedUser;

void initial_print(){
  //system("figlet -c PisiCh Bank");
  printf("What operation would you like to perform?\n");
  printf("1. Create a new account\n2. Check the balance of your account\n");
  printf("3. Deposit money into your account\n4. Withdraw money from your account\n");
  printf("5. Change any account details\n6. Delete an existing account\n");
  printf("Enter the number of your selection: ");
}

void insertAccToDb(struct Account *acc){
  FILE *accDB;
  char new_acc[MAX_NAME_LEN];
  char numb[16];
  char name[MAX_NAME_LEN];
  for(int i=0; i<MAX_NAME_LEN; i++) name[i] = (*acc).name[i];
  for (int i=0; i<16; i++) sprintf(&numb[i], "%d", (*acc).number[i]);
  sprintf(new_acc, "%s\n%s\n%ld\n%d\n%d", numb, name, acc->balance, acc->typeAcc, acc->PIN);
  accDB = fopen("src/accounts.json", "a");
  fwrite(new_acc, sizeof(char), strlen(new_acc), accDB);
  fclose(accDB);
  //system("figlet -c Account successfully created!");

}

int confirmAccount(struct Account *newAcc){
  char y_or_n, temp;
  char numb[16];
  printf("Please confirm your new account details:\n");
  printf("Account owner: %s\n", newAcc->name);
  for (int i=0; i<16; i++) sprintf(&numb[i], "%d", (*newAcc).number[i]);
  printf("Account number: %s\n", numb);
  printf("Current balance: %ld\n", newAcc->balance);
  scanf("%c", &temp);
  if((*newAcc).typeAcc == 1){
    printf("Account type: Savings\n");
    if((*newAcc).balance < 500)
      printf("This account will build interests\n");
    else printf("This account will not build interests\n"); 
  }
  if((*newAcc).typeAcc == 2){
    printf("Account type: Checks\n");
    if((*newAcc).balance < 1000)
      printf("This account will build interests\n");
    else printf("This account will not build interests\n"); 
  }
  printf("Is all of this information correct? (y/n) ");
  scanf("%c", &y_or_n);
  if(y_or_n == 121) return 1;
  if(y_or_n == 110) return 0;
  else return 2;
}

void create_savings(char *name){
  //system("figlet -c Savings Account");
  struct Account newAccount;
  long int temp_bal;
  char y_or_n, temp;

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  newAccount.typeAcc = 1;

  for(int i = 0; i < MAX_NAME_LEN; i++)
    newAccount.name[i] = *(name + i);

  srand(time(0));
  printf("%s, your new account number is: ", newAccount.name);

  for(int i = 0; i < 16; i++){
    newAccount.number[i] = rand() % 10;
    printf("%d", newAccount.number[i]);
  }
  printf("\n");

  printf("You need to deposit at least $500 so your account won't build interests overtime\n");
  printf("Enter the amount you would like to deposit in your new account: ");
  scanf("%ld", &temp_bal);

  if(temp_bal < 500){
    scanf("%c", &temp);
    printf("Your account will start building interests at the end of the month if you deposit less than $500, are you sure you want to do this? (y/n) ");
    scanf("%c", &y_or_n);

    if(y_or_n == 110){
      printf("Enter the amount you would like to deposit in your new account: ");
      scanf("%ld", &temp_bal);
    }
    if(y_or_n == 121 || temp_bal < 500){
      printf("Your account will start building interests in %d days\n", 31 - tm.tm_mday);
    }
  }
  newAccount.balance = temp_bal;
  int check = confirmAccount(&newAccount);
  if(check == 1) insertAccToDb(&newAccount);
  else if(check == 0) create_savings(name);
}
void create_checks(char *name){
  //system("figlet -c Checks Account");
  struct Account newAccount;
  long int temp_bal;
  char y_or_n, temp;

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  newAccount.typeAcc = 2;

  for(int i = 0; i < MAX_NAME_LEN; i++)
    newAccount.name[i] = *(name + i);
  srand(time(0));
  printf("%s, your new account number is: ", newAccount.name);

  for(int i = 0; i < 16; i++){
    newAccount.number[i] = rand() % 10;
    printf("%d", newAccount.number[i]);
  }
  printf("\n");

  printf("You need to deposit at least $1000 so your account won't build interests overtime\n");
  printf("Enter the amount you would like to deposit in your new account: ");
  scanf("%ld", &temp_bal);

  if(temp_bal < 1000){
    scanf("%c", &temp);
    printf("Your account will start building interests at the end of the month if you deposit less than $500, are you sure you want to do this? (y/n) ");
    scanf("%c", &y_or_n);

    if(y_or_n == 110){
      printf("Enter the amount you would like to deposit in your new account: ");
      scanf("%ld", &temp_bal);
    }
    if(y_or_n == 121 || temp_bal < 1000){
      printf("Your account will start building interests in %d days\n", 31 - tm.tm_mday);
    }
  }
  newAccount.balance = temp_bal;
  int check = confirmAccount(&newAccount);
  if(check == 1) insertAccToDb(&newAccount);
  else if(check == 0) create_checks(name);
}

void create_acc(){
  int test = 0;
  int *age = &test;
  int acc;
  char temp;
  char name[MAX_NAME_LEN];
  //system("figlet -c Create new account");
  printf("Enter your age: ");
  scanf("%d", age);
  while(*age <= 0){
    printf("That is not a valid age, please enter a valid age.\n");
    scanf("%d", age);
  }
  if(*age < 18){
    printf("You are not allowed to create a bank account if you are under 18 years old, come back in %d years.\n", 18 - *age);
    exit(0);
  }
  scanf("%c", &temp);
  printf("Enter your full name: ");
  scanf("%[^\n]s", name);
  //Check if this name isn't on Credit Bureau

  for(int i = 0; i < MAX_NAME_LEN; i++){
    if(name[i] >= 97 && name[i] <= 122 && name[i] != 32)
      name[i] = name[i] - 32;
  }

  printf("What kind of account would you like to open?\n");
  printf("1. Savings\n2. Checks\n");
  printf("Enter your selection: ");
  scanf("%d", &acc);
  while(acc < 1 || acc > 2){
    printf("That is not a valid selection, please enter a valid account type: ");
    scanf("%d", &acc);
  }
  if(acc == 1)
    create_savings(name);
  else if(acc == 2)
    create_checks(name);
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
  FILE *accDB;
  int number[16];
  char temp;
  char buffer[1024];
  printf("Enter your accounts number: ");
  for(int i = 0; i<16; i++) scanf("%d", &number[i]);
  //LEFT HERE
  accDB = fopen("src/accounts.json", "r");
  fread(buffer, sizeof(char), 1024, accDB);
  fclose(accDB);
  printf("%s",buffer);
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
