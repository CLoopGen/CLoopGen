#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int ml[400];
int liberty_mark;
int *libs1;
int liberties1;
int k;

void init_vars() {
    liberty_mark = 42;
    liberties1 = 400;

    libs1 = (int*)malloc(liberties1 * sizeof(int));
    for (int i = 0; i < liberties1; i++) {
        libs1[i] = i % 400;
    }

    for (int i = 0; i < 400; i++) {
        ml[i] = 0;
    }
}