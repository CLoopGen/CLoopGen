#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *src;
ptrdiff_t srcstride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

#define FILTER_SIZE 6
#define CM_SIZE 512
#define HEIGHT (1 << 14)
#define WIDTH 8

static uint8_t filter_data[FILTER_SIZE] = {8, 16, 24, 32, 16, 8};
static uint8_t cm_data[CM_SIZE];
static uint8_t *src_buffer;
static uint8_t *tmp_buffer;

void init_vars() {
    h = HEIGHT;
    srcstride = WIDTH;

    for (int i = 0; i < FILTER_SIZE; i++) {
        filter_data[i] = (i == 0 || i == 5) ? 8 : (i == 1 || i == 4) ? 16 : 24;
    }
    filter = filter_data;

    for (int i = 0; i < CM_SIZE; i++) {
        cm_data[i] = (uint8_t)((i * 13 + 7) % 256);
    }
    cm = cm_data;

    src_buffer = aligned_alloc(32, h * srcstride * sizeof(uint8_t));
    tmp_buffer = aligned_alloc(32, ((h + 6 - 1)) * 4 * sizeof(uint8_t));

    if (!src_buffer || !tmp_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < h * srcstride; i++) {
        src_buffer[i] = (uint8_t)(i % 256);
    }

    src = src_buffer + 2 * srcstride; // Adjust so that x-2 access is valid at start
    tmp = tmp_buffer;
}