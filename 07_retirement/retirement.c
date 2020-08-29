#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double account_balance(double balance, double rate, double contribution){
  double interest=  balance * rate/12;
  balance += interest;
  balance += contribution;
  return balance;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  int  tmonths= startAge-1;
  double balance=initial;
  for (int i=0; i<working.months;i++){
    tmonths++;
    printf("Age %3d month %2d you have $%.2lf\n", tmonths / 12, tmonths % 12, balance);
    balance=account_balance(balance,working.rate_of_return,working.contribution);
  }
  
  for (int j=0; j<retired.months;j++){
    tmonths++;
    printf("Age %3d month %2d you have $%.2lf\n", tmonths / 12, tmonths % 12, balance);
    balance=account_balance(balance,retired.rate_of_return,retired.contribution);
  }
}

int main (void){
  retire_info Working={489,1000,0.045};
  retire_info Retired={384,-4000,0.01};
  retirement(327,21345,Working,Retired);
  return EXIT_SUCCESS;

}
  
