#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned char Intersection;

Intersection board[421];
int string_number[400];
int str2 = 100;
int *libs1;
int liberties1;
int commonlibs;
int k;

void init_vars() {
    liberties1 = 2000000;
    commonlibs = 0;
    str2 = 199;

    libs1 = (int*)malloc(liberties1 * sizeof(int));
    for (int i = 0; i < liberties1; i++) {
        libs1[i] = 20 + (i % 380);
    }

    for (int i = 0; i < 421; i++) {
        board[i] = (i % 3) ? 1 : 2;
    }

    for (int i = 0; i < 400; i++) {
        string_number[i] = (i % 5) ? i % 7 : i % 3;
    }
}