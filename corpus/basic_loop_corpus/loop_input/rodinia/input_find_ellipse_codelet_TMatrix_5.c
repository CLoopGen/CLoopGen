#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int N;
int *bindex;
int i;

void init_vars() {
    N = 64 * 1024 * 1024; // 64 million elements, roughly 256MB for int array
    bindex = (int*)malloc(N * sizeof(int));
    if (!bindex) {
        exit(1);
    }
    i = 0;
}