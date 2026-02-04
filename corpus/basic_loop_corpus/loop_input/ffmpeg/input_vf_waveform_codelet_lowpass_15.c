#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dst_linesize;
int sliceh_start;
int sliceh_end;
int step;
int y;
int bg;
int dst_w;
int t0;
int t1;
uint8_t *dst0;
uint8_t *dst1;
uint8_t *src;
int x;

#define DATA_SIZE_MB 64
#define TOTAL_PIXELS (DATA_SIZE_MB * 1024 * 1024)
#define WIDTH_DEFAULT 1920
#define HEIGHT_DEFAULT (TOTAL_PIXELS / WIDTH_DEFAULT)

static uint8_t *src_data;
static uint8_t *dst0_data;
static uint8_t *dst1_data;

void init_vars() {
    dst_linesize = WIDTH_DEFAULT;
    sliceh_start = 0;
    sliceh_end = HEIGHT_DEFAULT;
    step = 1;
    bg = 0;
    dst_w = WIDTH_DEFAULT;
    t0 = 255;
    t1 = 128;
    x = 0;
    y = 0;

    size_t total_size = (size_t)dst_linesize * HEIGHT_DEFAULT;

    src_data = (uint8_t*)calloc(total_size, sizeof(uint8_t));
    dst0_data = (uint8_t*)calloc(total_size, sizeof(uint8_t));
    dst1_data = (uint8_t*)calloc(total_size, sizeof(uint8_t));

    if (!src_data || !dst0_data || !dst1_data) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        src_data[i] = rand() % 256;
    }

    src = src_data;
    dst0 = dst0_data;
    dst1 = dst1_data;
}