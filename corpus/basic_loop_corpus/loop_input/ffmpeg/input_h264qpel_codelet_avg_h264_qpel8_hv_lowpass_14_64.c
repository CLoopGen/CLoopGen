#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(uint16_t))

static uint16_t src_data[TOTAL_ELEMENTS];
static int32_t tmp_data[TOTAL_ELEMENTS];

void init_vars() {
    const int row_elements = 11; 
    const int rows = TOTAL_ELEMENTS / row_elements;
    
    h = rows - 5; 
    if (h <= 0) {
        h = 1;
    }

    srcStride = row_elements;
    tmpStride = row_elements;

    pad = 10;

    src = src_data;
    tmp = tmp_data;

    for (int i = 0; i < TOTAL_ELEMENTS; ++i) {
        src_data[i] = (uint16_t)(i % 1024);
    }
}