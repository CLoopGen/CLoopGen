#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
int *bindex;
int i;

void init_vars() {
    N = 64 * 1024 * 1024; // 64M elements, approximately 256MB for int array
    bindex = (int*)aligned_alloc(32, N * sizeof(int));
    if (!bindex) {
        exit(1);
    }
    i = 0;
}