#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define OUTPUT_SIZE (256 * 1024 * 1024 / sizeof(int16_t))
#define TEMP_SIZE 16
#define X_OFFSET_SIZE 4

int16_t *output;
unsigned int qmul;
int i;
int temp[TEMP_SIZE];
uint8_t x_offset[X_OFFSET_SIZE];

void init_vars() {
    output = (int16_t *)aligned_alloc(64, OUTPUT_SIZE * sizeof(int16_t));
    if (!output) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < OUTPUT_SIZE; idx++) {
        output[idx] = 0;
    }

    qmul = 12345U;

    for (int idx = 0; idx < TEMP_SIZE; idx++) {
        temp[idx] = (idx * 17) % 100 - 50;
    }

    x_offset[0] = 0;
    x_offset[1] = 16;
    x_offset[2] = 32;
    x_offset[3] = 48;

    i = 0;
}