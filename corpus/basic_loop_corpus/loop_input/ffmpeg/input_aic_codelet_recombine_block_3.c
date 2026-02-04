#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
uint8_t *scan;
int16_t **ext;
int i;
int j;

static int16_t *dst_buf;
static uint8_t *scan_buf;
static int16_t **ext_ptr_arr;
static int16_t *ext_data;

void init_vars() {
    size_t dst_size = 1 << 20;
    size_t scan_size = 64;
    size_t ext_total_size = 8 * (8 + 1);

    dst_buf = calloc(dst_size, sizeof(int16_t));
    scan_buf = malloc(scan_size * sizeof(uint8_t));
    ext_data = malloc(ext_total_size * sizeof(int16_t));
    ext_ptr_arr = malloc(9 * sizeof(int16_t*));

    if (!dst_buf || !scan_buf || !ext_data || !ext_ptr_arr) {
        exit(1);
    }

    for (size_t idx = 0; idx < scan_size; idx++) {
        scan_buf[idx] = idx % dst_size;
    }

    for (size_t idx = 0; idx < ext_total_size; idx++) {
        ext_data[idx] = idx;
    }

    for (int idx = 0; idx < 9; idx++) {
        ext_ptr_arr[idx] = &ext_data[idx * 8];
    }

    dst = dst_buf;
    scan = scan_buf;
    ext = ext_ptr_arr;
    i = 0;
    j = 0;
}