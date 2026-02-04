#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char Intersection;

int pos = 200;
int lively[400];
int other = 1;
int k;
int all_lively;
int delta[8] = { -201, -1, 1, 201, 0, 0, 0, 0 };
Intersection board[421];

void init_vars() {
    srand(time(NULL));

    for (int i = 0; i < 400; i++) {
        lively[i] = rand() % 2;
    }

    other = 1;
    all_lively = 1;

    for (int i = 0; i < 421; i++) {
        board[i] = rand() % 2;
    }

    pos = 200;
}