#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *pix1;
uint8_t *pix2;
ptrdiff_t stride;
int h;
int s;
int i;
uint32_t *sq;

#define DATA_SIZE_MB 64
#define BUFFER_SIZE (DATA_SIZE_MB * 1024 * 1024)
#define ROW_WIDTH 16
#define NUM_ROWS (BUFFER_SIZE / ROW_WIDTH)

static uint8_t local_pix1_buffer[BUFFER_SIZE];
static uint8_t local_pix2_buffer[BUFFER_SIZE];
static uint32_t local_sq_buffer[512]; // Covers range [-255 to 255] offset by 256

void init_vars() {
    // Initialize lookup table sq for differences from -255 to 255
    for (int diff = -255; diff <= 255; diff++) {
        local_sq_buffer[diff + 256] = (uint32_t)(diff * diff);
    }

    // Set stride to row width (16 bytes)
    stride = ROW_WIDTH;

    // Set number of rows to process (ensure we don't exceed buffer)
    h = NUM_ROWS;

    // Initialize sum
    s = 0;

    // Initialize pix1 and pix2 to point to buffers
    pix1 = local_pix1_buffer;
    pix2 = local_pix2_buffer;

    // Initialize sq lookup table pointer
    sq = local_sq_buffer;

    // Seed and fill buffers with random data to avoid optimization removal
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < BUFFER_SIZE; i++) {
        local_pix1_buffer[i] = (uint8_t)(rand() & 0xFF);
        local_pix2_buffer[i] = (uint8_t)(rand() & 0xFF);
    }
}