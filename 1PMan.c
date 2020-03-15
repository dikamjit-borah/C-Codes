// C program to print *
// in place of characters
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>// C program to print *
// in place of characters
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

float damage_S = 0.0;
float damage_N = 0.0;
float health_S = 0.0;
float health_N = 0.0;

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
bool password(){
    int pcount = 0;
    printf("password:\n");
    int attempts=3;
    int p = 0;
    do{
        char password[55] = "";
        attempts = attempts-1;
        do{
            password[p]=getch();
            if(password[p]!='\r'){
                printf("*");
            }
            p++;
        }while(password[p-1]!='\r');
        password[p-1]='\0';
        printf("%s", password);
        if(strcmp(password, "EGC251")==0)
        {
            return true;
        }
        else
        {
            printf("\nINCORRECT PASSWORD!!!\n");
            printf("%d attempts remaining.\n", attempts);
        }
        fflush(stdin);
    }while(attempts>0);
    return false;
}

void calculateHealth(float s, float n)
{
    float skill = RandomFloat(0.9, 1.1);
    health_S = health_S * skill - s;
    health_N = health_N * skill - n;
}


void calculateDamage(int s, int n)
{
    float rand_s = RandomFloat(0.05, 0.1);
    float rand_n = RandomFloat(0.05, 0.1);
    damage_S = n*health_S * rand_s;
    damage_N = s*health_N * rand_n;
    calculateHealth(damage_S, damage_N);
}

int main()
{
    int rand();
    bool t;
    t = password();
    if(t==true)
    {
        int rounds = 0;
        health_S = RandomFloat(20.0, 24.99);
        health_N = RandomFloat(20.0, 24.99);
        int punch_S;
        int punch_N;
        while(rounds<3)
        {
            printf("\n\tHealth of S = : %f\n\tHealth of N = : %f", health_S, health_N);
            if(health_N<3.5 || health_S<3.5)
            {

                if(health_N<0.5)
                    printf("\nS WINS VIA KNOCK-OUT");
                else if(health_S<0.5)
                    printf("\nN WINS VIA KNOCK-OUT");
                return;
            }
            else
            {
                printf("\nROUND %d", rounds+1);
                printf("\nENTER PUNCH S:    ");
                scanf("%d", &punch_S);
                printf("\nENTER PUNCH N:    ");
                scanf("%d", &punch_N);
                calculateDamage(punch_S, punch_N);
                rounds++;
            }

        }
        printf("\n\tHealth of S = : %f\n\tHealth of N = : %f", health_S, health_N);
        if(health_N<health_S)
                    printf("\nS WINS VIA KNOCK-OUT");
        else if(health_N>health_S)
                    printf("\nN WINS VIA KNOCK-OUT");
        else
                    printf("DRAW");
    }
    else
        printf("YOU ARE NOT WORTHY TO PLAY THE GAME!!!");
}

float damage_S = 0.0;
float damage_N = 0.0;
float health_S = 0.0;
float health_N = 0.0;

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
bool password(){
    int pcount = 0;
    printf("password:\n");
    int attempts=3;
    int p = 0;
    do{
        char password[55] = "";
        attempts = attempts-1;
        do{
            password[p]=getch();
            if(password[p]!='\r'){
                printf("*");
            }
            p++;
        }while(password[p-1]!='\r');
        password[p-1]='\0';
        printf("%s", password);
        if(strcmp(password, "EGC251")==0)
        {
            return true;
        }
        else
        {
            printf("\nINCORRECT PASSWORD!!!\n");
            printf("%d attempts remaining.\n", attempts);
        }
        fflush(stdin);
    }while(attempts>0);
    return false;
}

void calculateHealth(float s, float n)
{
    float skill = RandomFloat(0.9, 1.1);
    health_S = health_S * skill - s;
    health_N = health_N * skill - n;
}


void calculateDamage(int s, int n)
{
    float rand_s = RandomFloat(0.05, 0.1);
    float rand_n = RandomFloat(0.05, 0.1);
    damage_S = n*health_S * rand_s;
    damage_N = s*health_N * rand_n;
    calculateHealth(damage_S, damage_N);
}

int main()
{
    int rand();
    bool t;
    t = password();
    if(t==true)
    {
        int rounds = 0;
        health_S = RandomFloat(20.0, 24.99);
        health_N = RandomFloat(20.0, 24.99);
        int punch_S;
        int punch_N;
        while(rounds<3)
        {
            if(health_N<3.5 || health_S<3.5)
            {
                //printf("\n%f %f", health_S, health_N);
                if(health_N<3.5)
                    printf("S WINS VIA KNOCK-OUT");
                else if(health_S<3.5)
                    printf("N WINS VIA KNOCK-OUT");
                return;
            }
            else
            {
                printf("\nROUND %d", rounds+1);
                printf("\nENTER PUNCH S:    ");
                scanf("%d", &punch_S);
                printf("\nENTER PUNCH N:    ");
                scanf("%d", &punch_N);
                calculateDamage(punch_S, punch_N);
                rounds++;
            }
        }
    }
    else
        printf("YOU ARE NOT WORTHY TO PLAY THE GAME!!!");
}
