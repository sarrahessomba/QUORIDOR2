//
// Created by sarra on 30/10/2024.
//
#include <stdio.h>
void esthetique() {
    printf("X/Y ");
    for(int k=0; k<=9; k++) {
        printf("%d ", k);
    }
    for(int k=65; k<=71; k++) {
        printf("%c ", k);
    }
    printf("\n");
    printf("  ");
    for(int k=0; k<17; k++) {
        printf("--");
    }
    printf("\n");
}
void esthetique2(int i) {
    if(i>=0 && i<=9) {
        printf("%d | ", i);
    }else if(i>=9 && i<=17) {
        printf("%c | ", (55+i));
    }
}