#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M;
int *w;
size_t j;

void init_vars() {
    M = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB of data to ensure ~0.01 sec runtime
    w = (int*)calloc(M, sizeof(int));
    if (!w) {
        exit(1);
    }
    j = 0;
}