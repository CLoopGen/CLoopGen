#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char Intersection;

Intersection board[421];
int ml[400];
int liberty_mark = 1;
int maxlib = 300;
int *libs;
int *libs1;
int liberties2 = 350;
int commonlibs = 0;
int k = 0;

void init_vars() {
    const size_t data_size = 1 << 20;
    libs1 = (int*)malloc(liberties2 * sizeof(int));
    libs = (int*)malloc(maxlib * sizeof(int));

    for (int i = 0; i < 421; i++) {
        board[i] = (i % 7 == 0) ? 0 : (rand() % 255 + 1);
    }

    for (int i = 0; i < 400; i++) {
        ml[i] = (rand() % 2) ? liberty_mark + 1 : liberty_mark;
    }

    for (int i = 0; i < liberties2; i++) {
        libs1[i] = rand() % 421;
    }

    for (int i = 0; i < maxlib; i++) {
        libs[i] = -1;
    }

    commonlibs = 0;
    liberty_mark = 1;
}