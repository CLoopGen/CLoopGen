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

#define DATA_SIZE (64 * 1024) // ~64KB per buffer, safe and fast
#define SQ_TABLE_SIZE (512)

static uint8_t pix1_buf[DATA_SIZE];
static uint8_t pix2_buf[DATA_SIZE];
static uint32_t sq_table[SQ_TABLE_SIZE];

void init_vars() {
    // Initialize lookup table for squared differences: supports values from -255 to 255
    for (int idx = 0; idx < SQ_TABLE_SIZE; idx++) {
        int diff = idx - 256; // map [0..511] -> [-256..255]
        sq_table[idx] = (uint32_t)(diff * diff);
    }

    // Set global variables
    sq = sq_table;
    pix1 = pix1_buf;
    pix2 = pix2_buf;
    stride = 8; // each iteration advances by 8 bytes
    h = DATA_SIZE / stride; // number of complete rows we can process
    s = 0;
    i = 0;

    // Initialize pixel data to prevent out-of-bounds or undefined behavior
    for (int j = 0; j < DATA_SIZE; j++) {
        pix1_buf[j] = rand() & 0xFF;
        pix2_buf[j] = rand() & 0xFF;
    }
}