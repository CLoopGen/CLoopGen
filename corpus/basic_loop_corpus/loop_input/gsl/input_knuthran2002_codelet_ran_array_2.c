#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 134217728ULL  // ~128MB of data (each long is 8 bytes)

long *aa;
long *ran_x;
unsigned int i;
unsigned int j;

void init_vars() {
    aa = (long *)aligned_alloc(64, ARRAY_SIZE * sizeof(long));
    ran_x = (long *)aligned_alloc(64, 37 * sizeof(long));

    if (!aa || !ran_x) {
        exit(1);
    }

    for (size_t idx = 0; idx < ARRAY_SIZE; idx++) {
        aa[idx] = rand() % ((1L << 30) - 1);
    }

    for (int idx = 0; idx < 37; idx++) {
        ran_x[idx] = 0;
    }

    i = 0;
    j = 100;  // ensures j-100 >= 0 and j-37 is valid for first iteration; runs 37 times
}