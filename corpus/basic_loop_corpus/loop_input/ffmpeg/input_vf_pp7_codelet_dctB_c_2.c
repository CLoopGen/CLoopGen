#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (64 * 1024)

int16_t *dst;
int16_t *src;
int i;

static int16_t src_data[DATA_SIZE];
static int16_t dst_data[DATA_SIZE];

void init_vars() {
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        src_data[idx] = rand() % 1000;
        dst_data[idx] = 0;
    }
    
    src = src_data;
    dst = dst_data;
}