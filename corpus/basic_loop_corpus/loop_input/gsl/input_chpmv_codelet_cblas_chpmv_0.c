#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 131072; // 131072 * 2 * sizeof(float) = 1MB of data written
void *Y;
int incY = 1;
int i;
int iy = 0;

void init_vars() {
    Y = aligned_alloc(32, N * incY * 2 * sizeof(float));
    if (Y == NULL) {
        exit(1);
    }
}