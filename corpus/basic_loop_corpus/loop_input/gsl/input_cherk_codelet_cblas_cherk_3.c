#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float beta;
void *C;
int ldc;
int i;
int j;

void init_vars() {
    N = 2048;
    beta = 1.5f;
    ldc = N;
    C = aligned_alloc(32, 2 * N * N * sizeof(float));
}

void loop();