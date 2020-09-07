#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 30

struct Account{
  char acc_holder_name[MAX_LEN];
  int acc_number;
  float available_balance;  
};

struct Account accArr[MAX_LEN];
 
int num_acc;

void acc_bal(){
  
}

void withdraw(){
  int loc_acc_num;
  float withdraw_money;
 
  printf("Enter account number you want to withdraw money:");
  scanf("%d",&loc_acc_num);
  printf("\nThe current balance for account %d is %.2f \n", 
  loc_acc_num, accArr[loc_acc_num-1].available_balance);
  printf("\nEnter money you want to withdraw from account ");
  scanf("%f",&withdraw_money);
 
  if(loc_acc_num == accArr[loc_acc_num-1].acc_number){
    accArr[loc_acc_num-1].available_balance=
    accArr[loc_acc_num-1].available_balance-withdraw_money;
    printf("\nThe New balance for account %d is %.2f \n", 
    loc_acc_num, accArr[loc_acc_num-1].available_balance);
   }
  loc_acc_num++;
}

void deposit(){
  int loc_acc_num;
  float add_money;
 
  printf("Enter account number you want to deposit money:");
  scanf("%d",&loc_acc_num);
  printf("\nThe current balance for account %d is %.2f \n", 
  loc_acc_num, accArr[loc_acc_num-1].available_balance);
  printf("\nEnter money you want to deposit:  ");
  scanf("%f",&add_money);
 
  if (loc_acc_num == accArr[loc_acc_num-1].acc_number){
    accArr[loc_acc_num-1].available_balance=
    accArr[loc_acc_num-1].available_balance+add_money;
    printf("\nThe New balance for account %d is %.2f \n", 
    loc_acc_num, accArr[loc_acc_num-1].available_balance);
   }
  loc_acc_num++;
}

void acc_info(){
  register int num_acc = 0;
  while(accArr[num_acc].available_balance>0){
    printf("Account holder name: %s \n" , 
    accArr[num_acc].acc_holder_name);
    printf("Account number: %d \n" , 
    accArr[num_acc].acc_number);
    printf("Available balance: %.2f \n\n" , 
    accArr[num_acc].available_balance);
    num_acc++;
  }
}

void create_account(){
  char acc_holder_name[MAX_LEN];
  char temp;
  char name[MAX_LEN];
  int acc_number;
  float available_balance = 0;
  fflush(stdin);
  printf("\nEnter the account holder name: ");
  scanf("%c", &temp);
  scanf("%[^\n]s", name);
  printf("\nEnter the account number(1 to 10): ");
  scanf("%d", &acc_number);
  scanf("%c", &temp);
  strcpy(accArr[acc_number-1].acc_holder_name, acc_holder_name);
   accArr[acc_number-1].acc_number = acc_number;
   accArr[acc_number-1].available_balance = available_balance;
  for(int i = 0; i < MAX_LEN; i++){
    if(name[i] >= 97 && name[i] <= 122 && name[i] != 32)
      name[i] = name[i] - 32;
  }
  for(int i = 0; i < MAX_LEN; i++) accArr[acc_number-1].acc_holder_name[i] = name[i];
  //system("figlet -c Account has been created successfully");
  printf("Account holder name: %s \n" , accArr[acc_number-1].acc_holder_name);

  printf("Account number: %d \n" , accArr[acc_number-1].acc_number);
  printf("Available balance: %.2f \n" , accArr[acc_number-1].available_balance);
}

void initial_print(){
  printf("\n1. Create new account \n");
  printf("2. Deposit in your account \n");
  printf("3. Withdraw from your account \n");
  printf("4. Display account information \n");
  printf("6. Log out \n");
  printf("options \n\n");
}

int main(){
  char *option;
  num_acc = 0;
  //system("figlet -c Welcome to PisiCh Bank")
  initial_print();
  printf("Please enter any option to continue: ");
 
  scanf("%c", option);
  switch(*option){
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