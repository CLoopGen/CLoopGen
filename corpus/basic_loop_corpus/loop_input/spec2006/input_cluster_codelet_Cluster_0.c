#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int N;
int *coord;
int col;

void init_vars() {
    N = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB / 4 = 67M elements, adjust to fit ~0.01 sec
    coord = (int*)malloc(N * sizeof(int));
    if (!coord) {
        N = 0;  // fallback if malloc fails
    }
    col = 0;
}