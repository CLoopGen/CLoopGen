#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define ELEMENT_SIZE sizeof(uint16_t)
#define NUM_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / ELEMENT_SIZE)

static uint16_t src_data[NUM_ELEMENTS];
static int16_t tmp_data[NUM_ELEMENTS];

int16_t *tmp = tmp_data;
uint16_t *src = src_data;
int tmpStride = 4;
int srcStride = 4;
int h = (NUM_ELEMENTS / 4) - 5; 
int pad = 10;
int i = 0;

void init_vars() {
    for (int idx = 0; idx < NUM_ELEMENTS; ++idx) {
        src_data[idx] = (uint16_t)(idx % 32768);
    }
    for (int idx = 0; idx < NUM_ELEMENTS; ++idx) {
        tmp_data[idx] = 0;
    }
}