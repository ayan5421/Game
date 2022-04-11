#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int lads[100],lade[100],snks[100],snke[100],nols;
void entry(int a[])
{
    int i;
    for(i=0;i<nols;i++)
    { 
        scanf("%d",&a[i]);
    }
}
int dice()
{
    srand(time(NULL));
    return ((rand()%6)+1);
}
int snakeorladder(int a)
{
    int i;
    for(i=0;i<nols;i++)
    {
        if(a==lads[i])
        {
            printf("ladder(%d to %d)\n",lads[i],lade[i]);
            a=lade[i];
        } 
        if(a==snks[i])
        {
            printf("snake(%d to %d)\n",snks[i],snke[i]);
            a=snke[i];
        }
    }
    return a;
}
void main()
{
    int num1,num2,num3,i=69,d=0,sum1=0,sum2=0,sum3=0,ll;
    char g,h,x;
    printf("Press :\n1.to play with another player\n2.to play with computer\n");
    scanf("%d",&ll);
    printf("\n\n");
    printf("Enter the number of ladders or snakes (the total numer of snakes and ladders will be equal) :\n");
    scanf("%d",&nols); 
    printf("Enter the starting possition of all the ladders :\n");
    entry(lads);
    printf("Enter the ending possition of all the ladders :\n");
    entry(lade);
    printf("Enter the starting possition of all the snakes :\n");
    entry(snks);
    printf("Enter the ending possition of all the snakes :\n");
    entry(snke);
    printf("\nStarting the game.........\n\n");
    while(1)
    {
        printf("\nPlayer1-turn, Enter 0 to roll dice :\n");
        scanf("%s",&g);
        if(g==0)
        {
            num1=dice();
        }
        printf("Player1 scores %d\n",num1);
        sum1+=num1;
        if(sum1<100)
        {
            sum1=snakeorladder(sum1);
        }
        else if(sum1>100)
        {
            sum1-=num1;
        }
        else if(sum1==100)
        {
            printf("PLAYER1 WWWWOOOONNNN\n");
            d=1;
            printf("Position of player1 is = %d\n\n",sum1);
            break;
        }
        switch(ll)
        {
            case 1:
            printf("\nPlayer2-turn, Enter 0 to roll dice\n");
            scanf("%s",&h);
            if(h==0)
            {
                num2=dice();
            }
            sum2+=num2;
            printf("Player2 scores %d\n",num2);
            if(sum2<100)
            {
                sum2=snakeorladder(sum2);
            }
            else if(sum2>100)
            {
                sum2-=num2;
            }
            else if(sum2 == 100)
            {
                printf("PLAYER2 WWWOOOONNN\n");
                d=1;
                printf("Position of player2 is = %d\n\n",sum2);
                break;
            }
            break;
            case 2:
            printf("\nComputer's-turn\n");
            num3=dice();
            sum3+=num3;
            printf("Computer scores %d\n",num3);
            if(sum3<100)
            {
                sum3=snakeorladder(sum3);
            }
            if(sum3>100)
            {
                sum3-=num3;
            }
            else if(sum3==100)
            {
                printf("COMPUTER WWWOOOONNN\n");
                d=1;
                printf("Position of computer is = %d\n",sum3);
                break;
            }
            break;
        }
        if(d==1)
        {
            break;
        }
    }
}