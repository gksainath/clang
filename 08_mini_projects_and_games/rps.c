#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
int main()
{
    srand(time(0));

    
    int rsp,us=0,cs=0;
    printf("enter 1)rock 2)paper 3)scissor 4)end game\n");
    while(1)
    {
        int n=(rand()%3)+1;
        scanf("%d",&rsp);
        switch (rsp)
        {
        case 1:
            if(n==2)
            {
                printf("you ! loose paper crushes the rock!!\n");
                cs++;
            }
            else if (rsp==n)
            {
                printf("nothing happens... we both selected the samee\n");
            }
            
            else{
                printf("ughh!! you wonn!! you hit the scissor and it got broken!!\n ");
                us++;
            }
            break;
         case 2:
         if(n==3)
            {
                printf("you loose ! scissor destroyed the paper!!\n");
                cs++;
            }
            else if (rsp==n)
            {
                printf("nothing happens... we both selected the samee\n");
            }
            
            else{
                printf("ughh!! you wonn!! you crushed the rock!!\n");
                us++;
            }
         break;
         case 3:
          if(n==1)
            {
                printf("you ! loose rock crushed you\n");
                cs++;
            }
            else if (rsp==n)
            {
                printf("nothing happens... we both selected the samee\n");
            }
            
            else{
                printf("ughh!! you wonn!! you cutted down the paper!!\n");
                us++;
            }
         break;
         case(4):
        printf("calculating score.......");
        Sleep(3000);
        printf("your score:%d\n",us);
        printf("computer score:%d\n",cs);   
        if(us==cs)
        {
            printf("it's a draw!!");
        }
        else if (us>cs)
        {
            printf("you won!!");
        }
        else
        {
            printf("you loose");
        }
         return 0;
         break;
        default:
        printf("are you sure you selected number from 1 to 3??\n");
            break;
        }
    }
    return 0;
}