#include <stdio.h>

int main()
{
 int avbl= 1234;
 int pin;
 int bal=50000;
 int amt;
 int opt;
 int opt1;
 int yrn;
 
 printf("Enter the Pin");
 scanf("%d",&pin);
 if (pin==avbl)
 {
  do
  {
  
  
   
   
   

    printf("Enter any the service you want to use\n 1)balance enquiry\n2)pin change\n3)withdrawl\n4)depoist");
    scanf("%d",&opt);
    switch (opt){
      case 1:
         printf("your current balance is %d",bal);
         break;
         case 2:
         printf("enter the new pin");
         scanf("%d",&pin);
         printf("your pin has been changed!");
         break;
          case 3:
         printf("enter the amount you want to withdraw");
         scanf("%d",&amt);
         if(amt<=50000)
         {
            printf("the amount has been dispensed, should we show the balance?\n1)yes\n2)no");
            scanf("%d",&opt1);
           
            switch (opt1){
                case 1:
                printf("your current balance is %d",bal-amt);
                break;
                default:
                printf("thank you!");
            }
         }
         else 
         printf("insufficient balance");
          
         break;
         case 4:
         printf("Enter the amount you want to deposit");
         scanf("%d",&amt);
         printf("thank you now your current balance is %d",bal+amt);
         break;
         default:
         printf("wrong option entered");
      }

    }
    while (yrn==1);
    
    printf("do you want to open the menu?\n 1)yes2)no");
    scanf("%d",&yrn);
   
} 

 else
 printf("you entered the wrong pin");
 return 0;
}