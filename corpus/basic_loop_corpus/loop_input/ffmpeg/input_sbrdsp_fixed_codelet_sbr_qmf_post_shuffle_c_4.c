#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int W[32][2];
int *z;
int k;

void init_vars() {
    z = (int*)malloc(64 * sizeof(int));
    if (!z) {
        exit(1);
    }
    for (int i = 0; i < 64; i++) {
        z[i] = i + 1;
    }
}