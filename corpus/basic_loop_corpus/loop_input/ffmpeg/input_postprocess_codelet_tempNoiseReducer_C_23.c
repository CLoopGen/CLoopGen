#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int stride;
uint8_t *tempBlurred;
int y;

static uint8_t *src_data;
static uint8_t *tempBlurred_data;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB
    src_data = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    tempBlurred_data = (uint8_t *)calloc(data_size, sizeof(uint8_t));

    if (!src_data || !tempBlurred_data) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src_data[i] = rand() % 256;
        tempBlurred_data[i] = rand() % 256;
    }

    stride = 16384; // Ensure 8x8 block fits within stride boundaries
    src = src_data;
    tempBlurred = tempBlurred_data;
    y = 0;
}