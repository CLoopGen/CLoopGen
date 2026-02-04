#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
int *bindex;
int i;

void init_vars() {
    N = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB of data to target ~0.01 sec on modern CPU
    bindex = (int*)malloc(N * sizeof(int));
    if (!bindex) {
        exit(1);
    }
    i = 0;
}