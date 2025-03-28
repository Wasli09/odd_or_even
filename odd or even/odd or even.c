#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32 
#include <windows.h>
#define _sleep() Sleep(1)
#endif

#ifdef __unix__
#include <unistd.h>
#define _sleep() sleep(1)
#endif



typedef struct dice{
    int dice1;
    int dice2;
}dice;

dice dice_mechanics(dice d){
    int x, y;
    srand(time(NULL));
    x = rand() % 6 + 1 ;
    y = rand() % 6 + 1 ;
    d.dice1 = x;
    d.dice2 = y;
    return d;
}

void loading(){
    char *points[] = { ".", "..", "..."};
    for(int i = 0 ; i < 3 ; i++){
        printf("rolling dice%s \r", points[i]);
        fflush(stdout);
        _sleep();
    }
    printf("\n");
}

int main(){
    dice d;
    char m, n, z;
    printf("############################\n");
    printf("# welcome to \"odd or even\" #\n");
    printf("############################\n");

    do{
        printf("\nplease pick odd(o) or even(e): ");
        scanf(" %c",&m);

        if(m != 'o' && m != 'e'){
            printf("please chose a viable option\n");
        }
    
        else{

            d = dice_mechanics(d);
            loading();
            printf("the dice is: \"%d\" \"%d\"\n", d.dice1, d.dice2);

            if((d.dice1 + d.dice2) % 2 == 0){
                n = 'e';
                if(n == m){
                    printf("YOU WIN :)\n");
                }

                else{
                    printf("YOU LOSE :(\n");
                }
            }

            else{
                n = 'o';

                if(n == m){
                printf("YOU WIN :)\n");
                }

                else{
                printf("YOU LOSE :(\n");
                }
            }
        }
        printf("would like to play again (y/n): ");
        scanf(" %c", &z);
    }

    while (z == 'y');
    printf("tnx for playing\n");
    return 0;

}
