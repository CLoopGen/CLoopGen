#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *top;
int16_t *bottom;
int i;
int a;
int b;
int c;
int d;
int d1;
int d2;
int rnd1;
int rnd2;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of int16_t data
static int16_t *top_buffer;
static int16_t *bottom_buffer;

void init_vars() {
    top_buffer = aligned_alloc(32, (DATA_SIZE + 64) * sizeof(int16_t));
    bottom_buffer = aligned_alloc(32, (DATA_SIZE + 64) * sizeof(int16_t));

    if (!top_buffer || !bottom_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < DATA_SIZE + 64; j++) {
        top_buffer[j] = rand() % 1000;
        bottom_buffer[j] = rand() % 1000;
    }

    top = top_buffer + 48;
    bottom = bottom_buffer;

    rnd1 = 3;
    rnd2 = 5;
}