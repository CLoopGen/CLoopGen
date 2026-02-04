#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 1024;
int linesize = 1024;
int sat_linesize = 1025;
int starty = 0;
int endy = 256;
uint64_t *sat;
uint64_t *square_sat;
uint8_t *src;
int x;
int y;

void init_vars() {
    size_t total_size = (size_t)(endy - starty) * sat_linesize;
    sat = aligned_alloc(64, total_size * sizeof(uint64_t));
    square_sat = aligned_alloc(64, total_size * sizeof(uint64_t));
    src = aligned_alloc(64, (size_t)(endy - starty) * linesize * sizeof(uint8_t));

    for (size_t i = 0; i < total_size; i++) {
        sat[i] = 0;
        square_sat[i] = 0;
    }
    for (size_t i = 0; i < (size_t)(endy - starty) * linesize; i++) {
        src[i] = rand() & 0xFF;
    }
}