#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int linesize;
int *x_start;
int *y_start;
uint8_t *ref;
int ref_linesize;
int y_end;
int same_column;

static uint8_t *buf_data;
static uint8_t *ref_data;
static int x_start_val;
static int y_start_val;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    size_t width = 8192;
    size_t height = total_data_size / width;
    if (height == 0) height = 1;
    if (height > 16384) height = 16384;
    width = total_data_size / height;

    buf_data = aligned_alloc(32, width * height);
    ref_data = aligned_alloc(32, width * height);

    if (!buf_data || !ref_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < width * height; i++) {
        buf_data[i] = (uint8_t)(i & 0xFF);
        ref_data[i] = (uint8_t)(i & 0xFF); // make them equal initially
    }

    linesize = (int)width;
    ref_linesize = (int)width;

    x_start_val = 0;
    y_start_val = 0;
    x_start = &x_start_val;
    y_start = &y_start_val;

    y_end = (int)(height - 1);
    if (y_end < 0) y_end = 0;

    buf = buf_data;
    ref = ref_data;

    same_column = 1;
}