#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int ldc = 1024;
int i;
int j;

float *C_data;
void *C;

void init_vars() {
    size_t total_size = ldc * N * sizeof(float) * 2; // Each element accessed as float[2*(...)]
    C_data = (float *)calloc(total_size / sizeof(float), sizeof(float));
    if (!C_data) {
        exit(1);
    }
    C = (void *)C_data;
}