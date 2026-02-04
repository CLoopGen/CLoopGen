#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
uint8_t *scan;
int16_t **ext;
int i;

static int16_t *dst_buf;
static uint8_t *scan_buf;
static int16_t *ext_inner;
static int16_t **ext_buf;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of input data (~0.01 sec on modern CPU)

    dst_buf = calloc(data_size, sizeof(int16_t));
    scan_buf = malloc(data_size * sizeof(uint8_t));
    ext_inner = malloc(data_size * sizeof(int16_t));
    ext_buf = malloc(sizeof(int16_t*));
    
    if (!dst_buf || !scan_buf || !ext_inner || !ext_buf) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < data_size; ++j) {
        scan_buf[j] = (uint8_t)(j % 256); // ensure within [0,255]
        ext_inner[j] = (int16_t)j;
    }

    dst = dst_buf;
    scan = scan_buf;
    ext = ext_buf;
    ext[0] = ext_inner;
}