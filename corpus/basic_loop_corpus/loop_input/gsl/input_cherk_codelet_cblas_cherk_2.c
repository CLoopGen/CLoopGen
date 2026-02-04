#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;
float beta = 2.5f;
void *C = NULL;
int ldc = 4096;
int i = 0;
int j = 0;

void init_vars() {
    C = aligned_alloc(32, sizeof(float) * 2 * ldc * N);
    if (!C) {
        exit(1);
    }
}