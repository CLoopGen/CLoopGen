#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE ((DATA_SIZE_MB * 1024 * 1024) / sizeof(int16_t))

int16_t *vector;
int length;
int i;
int absolute;
int maximum;

void init_vars() {
    length = ARRAY_SIZE;
    vector = (int16_t *)aligned_alloc(32, length * sizeof(int16_t));
    if (!vector) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    srand((unsigned int)time(NULL));
    for (int idx = 0; idx < length; idx++) {
        vector[idx] = (int16_t)(rand() % 65536 - 32768);
    }

    i = 0;
    absolute = 0;
    maximum = 0;
}