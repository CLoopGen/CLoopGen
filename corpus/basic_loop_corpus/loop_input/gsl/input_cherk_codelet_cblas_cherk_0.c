#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int ldc = 1024;
int i, j;
float *C_data;
void *C;

void init_vars() {
    C_data = (float *)aligned_alloc(32, sizeof(float) * ldc * N * 2);
    if (!C_data) {
        exit(1);
    }
    C = (void *)C_data;
}