#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 30

struct Account{
  char acc_holder_name[MAX_LEN];
  int first_acc_number;
  char acc_numbers[15];
  float available_balance;  
};

struct Account accArr[MAX_LEN];
 
int num_acc, past_operations;

void ask();

void acc_bal(){
  int loc_acc_num;
 
  printf("Enter your first account number to see your available balance: ");
  scanf("%d",&loc_acc_num);
  printf("\nThe current balance for account %d", loc_acc_num);
  for(int i = 0; i<15;i++) printf("%d", accArr[loc_acc_num-1].acc_numbers[i]);
  printf(" is %.2f\n", accArr[loc_acc_num-1].available_balance);
  ask();
}

void withdraw(){
  int loc_acc_num;
  float withdraw_money;
 
  printf("Enter your first account number where you want to withdraw money from: ");
  scanf("%d",&loc_acc_num);
  printf("\nThe current balance for account %d", loc_acc_num);
  for(int i = 0; i<15;i++) printf("%d", accArr[loc_acc_num-1].acc_numbers[i]);
  printf(" is %.2f\n", accArr[loc_acc_num-1].available_balance);
  printf("\nEnter the amount of money you want to withdraw from this account: ");
  scanf("%f",&withdraw_money);
  while(withdraw_money > accArr[loc_acc_num-1].available_balance){
    printf("You can't withdraw more money than you actually have in your account, please enter another amount.\n");
    scanf("%f",&withdraw_money);
  }
  if(loc_acc_num == accArr[loc_acc_num-1].first_acc_number){
    accArr[loc_acc_num-1].available_balance=
    accArr[loc_acc_num-1].available_balance-withdraw_money;
    printf("\nThe new balance of this account is %.2f \n", accArr[loc_acc_num-1].available_balance);
   }
  loc_acc_num++;
  ask();
}

void deposit(){
  int loc_acc_num;
  float add_money;
 
  printf("Enter your first account number where you want to deposit money: ");
  scanf("%d",&loc_acc_num);
  printf("\nThe current balance for account %d", loc_acc_num);
  for(int i = 0; i<15;i++) printf("%d", accArr[loc_acc_num-1].acc_numbers[i]);
  printf(" is %.2f\n", accArr[loc_acc_num-1].available_balance);
  printf("\nEnter the amount of money you want to deposit to this account: ");
  scanf("%f",&add_money);
 
  if (loc_acc_num == accArr[loc_acc_num-1].first_acc_number){
    accArr[loc_acc_num-1].available_balance=
    accArr[loc_acc_num-1].available_balance+add_money;
    printf("\nThe new balance for this account is %.2f \n", accArr[loc_acc_num-1].available_balance);
   }
  loc_acc_num++;
  ask();
}

void acc_info(){
  register int num_acc = 0;
  while(accArr[num_acc].available_balance>0){
    printf("Account holder name: %s \n", accArr[num_acc].acc_holder_name);
    printf("Account number: %d", accArr[num_acc].first_acc_number);
    for(int i = 0; i<15; i++) printf("%d", accArr[num_acc].acc_numbers[i]);
    printf("\n");
    printf("Available balance: %.2f \n\n", accArr[num_acc].available_balance);
    num_acc++;
  }
  ask();
}

void create_account(){
  char acc_holder_name[MAX_LEN];
  char temp;
  char name[MAX_LEN];
  int acc_first_numb;
  char other_acc_numbs[15];
  float available_balance = 0;
  fflush(stdin);
  printf("\nEnter the account holder name: ");
  scanf("%c", &temp);
  scanf("%[^\n]s", name);
  printf("\nIn PisiChBank you can choose your first account number(1 to 9): ");
  scanf("%d", &acc_first_numb);
  for(int i = 0;i<15;i++) accArr[acc_first_numb-1].acc_numbers[i] = rand() % 10;
  scanf("%c", &temp);

  strcpy(accArr[acc_first_numb-1].acc_holder_name, acc_holder_name);
   accArr[acc_first_numb-1].first_acc_number = acc_first_numb;
   accArr[acc_first_numb-1].available_balance = available_balance;

  for(int i = 0; i < MAX_LEN; i++){
    if(name[i] >= 97 && name[i] <= 122 && name[i] != 32)
      name[i] = name[i] - 32;
  }
  for(int i = 0; i < MAX_LEN; i++) accArr[acc_first_numb-1].acc_holder_name[i] = name[i];
  //system("figlet -c Account has been created successfully");
  printf("Account holder name: %s \n" , accArr[acc_first_numb-1].acc_holder_name);

  printf("Account number: %d" , accArr[acc_first_numb-1].first_acc_number);
  for(int i = 0; i<15; i++) printf("%d", accArr[acc_first_numb-1].acc_numbers[i]);
  printf("\n");
  printf("Available balance: %.2f \n" , accArr[acc_first_numb-1].available_balance);
  ask();
}

void initial_print(){
  printf("\n1. Create new account \n");
  printf("2. Deposit in your account \n");
  printf("3. Withdraw from your account \n");
  printf("4. Display account information \n");
  printf("5. Check my account balance\n");
  printf("6. Log out \n");
}

int main(){
  char option, temp;
  num_acc = 0;
  //system("figlet -c Welcome to PisiCh Bank")
  initial_print();
  printf("Please enter any option to continue: ");
  if(past_operations == 1)
    scanf("%c", &temp);
  scanf("%c", &option);
  switch(option){
    case '1': create_account();
      break;
    case '2': deposit();
      break;
    case '3': withdraw();
      break;
    case '4': acc_info();
      break;
    case '5': acc_bal();
      break;
    case '6': exit(0);
    default:
      printf("Please enter any option to continue \n");
      break;
  }
  return 0;
}

void ask(){
  char select, temp;
  printf("Do you want to perform another operation? (y/n) ");
  if (past_operations == 1)
    scanf("%c", &temp);
  scanf("%c", &select);
  past_operations = 1;
  switch(select){
    case 'y': main();
    case 'n': exit(0);
    default: exit(0);
  }
}