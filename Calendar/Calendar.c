#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void delay(int milliseconds);
int main()
{
    printf("*****************************CALENDER***************************\n");
    system("COLOR E5");
    int k=0;
    int year;
    int month;
    int i;
    int j;
    int tdays=0;
    int mdays=0;
    int d;
    int x;
    int m;
    int y;
    int r;
    int s;
    int t;
    int u;
    printf("year please! :");
    scanf("%d",&year);
    printf("month please! : ");
    scanf("%d",&month);
    int ydays=0;
    for(j=1990;j<year;j++){
        if(j%4==0){
            if(j%100==0){
                if(j%8==0){
                    ydays=ydays+366;
                }else{
                ydays=ydays+365;
                }
            }else{
            ydays=ydays+366;
            }
        }else{
        ydays=ydays+365;
        }
    }
    if(month>1){
    for(i=1;i<=month-1;i++){
      if(i<=7){
        if(i==2){
            if(year%4==0){
                    if(year%100==0){
                        if(year%8==0){
                mdays=mdays+29;
                        }
                        else{
                            mdays=mdays+28;
                        }
                    }
                    else{
                        mdays=mdays+29;
                    }
            }else{
            mdays=mdays+28;
            }
        }
        else if(i%2!=0){
            mdays=mdays+31;
        }
        else{
            mdays=mdays+30;
        }
        }else{
        if(i%2!=0){
            mdays=mdays+30;
        }else{
        mdays=mdays+31;
        }
        }
    }
    }
    d=mdays+ydays;
    x=d%7;

    /* defining u */
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        u=31;
    }
    else if(month==4||month==6||month==9||month==11){
        u=30;
    }
    else{
        if(year%4==0){
            if(year%100==0){
                if(year%8==0){
                    u=29;
                }else{
                u=28;
                }
            }else{
            u=29;
            }
        }else{
        u=28;
        }
    }

    printf("s\tm\tt\tw\tt\tf\ts\n");
    for(m=0;m<=x;m++){
        printf(" \t");
    }
    int c=1;
    for(y=x+1;y<=6;y++){

        printf("%d\t",c);
        delay(200);
        c=c+1;
    }
    printf("\n");
    for(r=1;r<=4;r++){
            for(s=1;s<=7;s++){
        printf("%d\t",c);
        delay(200);
        c=c+1;
        if(c>u){
            break;
        }
    }
    printf("\n");
    }


    return 0;
}
void delay(int milliseconds)
{
    long pause;
    clock_t now,then;
    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
    now = clock();
}
