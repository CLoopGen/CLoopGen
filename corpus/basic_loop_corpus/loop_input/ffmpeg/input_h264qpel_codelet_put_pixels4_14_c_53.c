#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

uint8_t *block;
uint8_t *pixels;
ptrdiff_t line_size;
int h;
int i;

#define DATA_SIZE (128 << 20) // 128 MB
#define LINE_WIDTH 64
#define NUM_LINES (DATA_SIZE / LINE_WIDTH)

static uint8_t block_data[DATA_SIZE];
static uint8_t pixels_data[DATA_SIZE];

void init_vars() {
    line_size = LINE_WIDTH;
    h = NUM_LINES;
    i = 0;
    block = block_data;
    pixels = pixels_data;
}