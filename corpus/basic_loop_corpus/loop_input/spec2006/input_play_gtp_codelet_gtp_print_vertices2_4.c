#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int n = 361;
int *moves;
int movei[361];
int movej[361];
int k;

void init_vars() {
    moves = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        moves[i] = (i + 1) * (19 + 1); 
    }
}