#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * 1024 * 1024 / sizeof(long))

long aa[ARRAY_SIZE];
long ran_x[ARRAY_SIZE];
unsigned int j;

void init_vars() {
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        ran_x[i] = rand() ^ (rand() << 15);
    }
    j = 0;
}