#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Intersection;

Intersection board[421];
int ml[400];
int liberty_mark;
int *libs1;
int liberties2;
int commonlibs;
int k;

void init_vars() {
    // Initialize scalar variables
    liberty_mark = 42;
    liberties2 = 300;  // Ensure this is <= 400 to respect ml bounds and control loop count
    commonlibs = 0;

    // Allocate and initialize libs1 array
    libs1 = (int*)malloc(liberties2 * sizeof(int));
    for (int i = 0; i < liberties2; i++) {
        // Ensure libs1[k] is a valid index into board[421] and ml[400]
        libs1[i] = rand() % 400;  // Value in [0, 399] valid for both board (size 421) and ml (size 400)
    }

    // Initialize board array (size 421)
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 2 == 0) ? 0 : 1;  // Alternate values to ensure some pass, some fail
    }

    // Initialize ml array (size 400)
    for (int i = 0; i < 400; i++) {
        ml[i] = (rand() % 50) + 1;  // Random in [1,50], so ml[x] != liberty_mark likely but not guaranteed
    }
}