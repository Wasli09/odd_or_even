#include <stdio.h>
#include <time.h>
#include <windows.h>
void dice_mechanics();
typedef struct dice
{
int dice1;
int dice2;
}dice;

void dice_mechanics(dice *d)
{
    int x, y;
    srand(time(0));
    x = rand() % 6 + 1 ;
    y = rand() % 6 + 1 ;
    d->dice1 = x;
    d->dice2 = y;
}

int main()
{
dice *d;
char m, n, z;
do{
printf("welcome to \"odd or even\"\n");
Sleep(500);
printf("please pick odd (o) or even (e)\n");
scanf(" %c",&m);

if(m != 'o' && m != 'e')
{
    printf("please chose viable choice");
    return 0;
}

else{
dice_mechanics(d);
printf("the dice is: \"%d\" \"%d\"\n", d->dice1, d->dice2);
Sleep(400);
if((d->dice1 + d->dice2) % 2 == 0)
{
    n = 'e';
    if(n == m)
    {
        printf("YOU WIN :)\n");
    }
    else
    {
        printf("YOU LOSE:(\n");
    }
}

else
{
    n = 'o';
    if(n == m)
    {
        printf("YOU WIN :)\n");
    }
    else
    {
        printf("YOU LOSE:(\n");
    }
}
}
Sleep(1000);
printf("would like to play again (y/n)\n");
scanf(" %c",&z);

}
while (z == 'y');
    printf("tnx for playing");
    Sleep(1000);
    return 0;
}