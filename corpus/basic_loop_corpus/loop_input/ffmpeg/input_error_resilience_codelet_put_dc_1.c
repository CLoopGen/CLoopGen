#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dest_cb;
uint8_t *dest_cr;
int *linesize;
int dcu = 64;
int dcv = 128;
int y;

void init_vars() {
    const size_t dest_size = 1 << 20; // 1MB
    dest_cb = (uint8_t *)calloc(dest_size, sizeof(uint8_t));
    dest_cr = (uint8_t *)calloc(dest_size, sizeof(uint8_t));
    linesize = (int *)malloc(3 * sizeof(int));
    linesize[1] = 128;
    linesize[2] = 128;
}