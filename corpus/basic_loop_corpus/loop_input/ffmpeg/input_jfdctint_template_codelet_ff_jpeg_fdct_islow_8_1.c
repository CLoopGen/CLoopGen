#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
    const size_t data_size_mb = 64;
    total_elements = (data_size_mb * 1024 * 1024) / sizeof(int16_t);
    
    data_buffer = aligned_alloc(32, total_elements * sizeof(int16_t));
    
    if (!data_buffer) {
        exit(1);
    }
    
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < total_elements; i++) {
        data_buffer[i] = (int16_t)(rand() % 65536 - 32768);
    }
    
    dataptr = data_buffer;
    ctr = 8 - 1;
}

void cleanup() {
    if (data_buffer) {
        free(data_buffer);
        data_buffer = NULL;
    }
}