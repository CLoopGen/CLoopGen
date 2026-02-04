#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int linesize;
int *y_start;
uint8_t *ref;
int ref_linesize;
int x_end;
int y_end;
int same_column;

static uint8_t *buf_data;
static uint8_t *ref_data;
static int y_start_val;

void init_vars() {
    const int height = 8192;
    const int width = 4096;
    x_end = width - 1;
    y_end = height - 1;
    linesize = width;
    ref_linesize = width;
    same_column = 1;

    buf_data = aligned_alloc(32, (size_t)height * width);
    ref_data = aligned_alloc(32, (size_t)height * width);
    y_start_val = 0;
    y_start = &y_start_val;

    if (!buf_data || !ref_data) {
        exit(1);
    }

    for (int i = 0; i < height * width; i++) {
        buf_data[i] = (uint8_t)(i & 0xFF);
        ref_data[i] = (uint8_t)(i & 0xFF);
    }

    buf = buf_data;
    ref = ref_data;
}