#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB of data

int16_t *out;
int i;
int j;
int t;
int16_t *ptr1;
int16_t *ptr2;
int coef;

static int16_t *out_buffer;
static int16_t *ptr1_buffer;
static int16_t *ptr2_buffer;

void init_vars() {
    out_buffer = (int16_t*)calloc(DATA_SIZE, sizeof(int16_t));
    ptr1_buffer = (int16_t*)calloc(DATA_SIZE + 1000, sizeof(int16_t)); // extra padding for ptr1 += 30
    ptr2_buffer = (int16_t*)calloc(DATA_SIZE, sizeof(int16_t));

    if (!out_buffer || !ptr1_buffer || !ptr2_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    out = out_buffer;
    ptr1 = ptr1_buffer;
    ptr2 = ptr2_buffer;

    i = 0;
    j = 3;
    t = 0;
    coef = 1000;

    // Initialize some sample values to ensure controlled execution
    for (size_t idx = 0; idx < DATA_SIZE / 2; idx++) {
        ptr1_buffer[idx] = (int16_t)(idx % 500);
    }
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        ptr2_buffer[idx] = (int16_t)(idx % 30000);
    }
}