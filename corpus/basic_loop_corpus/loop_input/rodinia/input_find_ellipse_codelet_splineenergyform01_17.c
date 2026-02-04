#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int N = 65536000; // Approx. 256MB for int array (65536000 * 4 bytes)
int *bindex;

void init_vars() {
    bindex = (int*)aligned_alloc(32, N * sizeof(int));
    if (!bindex) {
        exit(1);
    }
}