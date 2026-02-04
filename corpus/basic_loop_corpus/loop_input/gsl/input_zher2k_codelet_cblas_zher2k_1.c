#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 512;
int ldc = 512;
int i;
int j;

double C_data[512 * 512 * 2] __attribute__((aligned(32)));

void *C = (void*)C_data;

void init_vars() {
    N = 512;
    ldc = 512;
    i = 0;
    j = 0;
}