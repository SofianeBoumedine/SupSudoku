#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int choseLvl(){
    int l;
    choselvl:
    printf("\nWelcome to SupSudoku :) \nChoose your level (1, 2, 3):");
    scanf("%d",&l);
    if(l != 1 && l != 2 && l != 3){
        fflush(stdin);
        goto choselvl;
    }
    return l;
}

struct Entry placeNumber(){
    struct Entry entry;
    printf("\nAdd a number:\nPosition:");
    scanf("%s",entry.pos);
    printf("Number:");
    scanf("%d",&entry.number);
    return entry;
}
