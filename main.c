#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void initial_print(){
    system("figlet -c PisiCh Bank");
    printf("What operation would you like to perform?\n");
}


int main(){
    initial_print();
}
