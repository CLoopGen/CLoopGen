#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int ldc = 1024;
int i, j;

double *C_data;
void *C;

void init_vars() {
    C_data = (double *)calloc(2 * ldc * N, sizeof(double));
    if (!C_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    C = (void *)C_data;
}