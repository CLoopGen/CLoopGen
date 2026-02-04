#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * 1024 * 1024 / sizeof(int))

int markers[ARRAY_SIZE];
int sum;
int max;
int i;

void init_vars() {
    for (int j = 0; j < ARRAY_SIZE; j++) {
        markers[j] = rand() % 10000;
    }
    sum = 0;
    max = 0;
    i = 0;
}