#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *pix1;
uint8_t *pix2;
ptrdiff_t stride;
int h;
int s;
int i;
uint32_t *sq;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB for substantial runtime (~0.01 sec on modern CPU)

static uint8_t pix1_data[DATA_SIZE];
static uint8_t pix2_data[DATA_SIZE];
static uint32_t sq_data[512]; // sq indexed by differences in pixel values (-255 to 255), centered at 256

void init_vars() {
    // Initialize lookup table for squared differences
    for (int idx = 0; idx < 512; idx++) {
        int diff = idx - 256;
        sq_data[idx] = (uint32_t)(diff * diff);
    }

    // Set stride to 64 bytes (common cache line multiple, simulates image row step)
    stride = 64;

    // Ensure each row has 4 pixels accessed, so we need at least 4 bytes per row
    if (stride < 4) {
        stride = 4;
    }

    // Number of rows: choose h such that total data fits and loop takes noticeable time
    h = DATA_SIZE / stride;

    // Cap h to ensure we don't overflow buffer
    if (h > DATA_SIZE / stride) {
        h = DATA_SIZE / stride;
    }

    // Initialize pixel pointers to start of static arrays
    pix1 = pix1_data;
    pix2 = pix2_data;

    // Initialize sum variable
    s = 0;

    // Initialize the lookup table pointer
    sq = sq_data + 256; // Now sq[x - y] directly indexes correct squared difference

    // Initialize test data with non-zero pattern
    for (int j = 0; j < DATA_SIZE; j++) {
        pix1_data[j] = (uint8_t)(j & 0xFF);
        pix2_data[j] = (uint8_t)((j + 16) & 0xFF);
    }
}