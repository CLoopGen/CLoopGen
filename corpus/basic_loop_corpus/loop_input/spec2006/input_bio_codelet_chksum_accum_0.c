#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int int32;
typedef unsigned int uint32;
typedef unsigned char uint8;

int32 n_el;
uint32 sum;
int32 i;
uint8 *i8;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on modern CPU
    n_el = data_size;
    sum = 0;
    i = 0;

    i8 = (uint8*)malloc(n_el * sizeof(uint8));
    if (!i8) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize array with pseudo-random data for realistic access pattern
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < n_el; ++idx) {
        i8[idx] = (uint8)(rand() % 256);
    }
}