#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int tmp0;
int tmp1;
int tmp2;
int tmp3;
int tmp4;
int tmp5;
int tmp6;
int tmp7;
int tmp10;
int tmp11;
int tmp12;
int tmp13;
unsigned int z1;
unsigned int z2;
unsigned int z3;
unsigned int z4;
unsigned int z5;
int16_t *dataptr;
int ctr;

static int16_t *data_buffer;
static size_t total_elements;

void init_vars() {
    const size_t data_size = 131072; // ~256KB of data (131072 * 2 bytes)
    total_elements = data_size;
    data_buffer = aligned_alloc(32, total_elements * sizeof(int16_t));
    
    if (!data_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < total_elements; i++) {
        data_buffer[i] = (int16_t)(i % 512 - 256);
    }

    dataptr = data_buffer;
    ctr = 0;
    tmp0 = 0;
    tmp1 = 0;
    tmp2 = 0;
    tmp3 = 0;
    tmp4 = 0;
    tmp5 = 0;
    tmp6 = 0;
    tmp7 = 0;
    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    tmp13 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    z4 = 0;
    z5 = 0;
}