#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 1024;
int linesize = 1024 * sizeof(uint16_t);
int sat_linesize = 1025;
int starty = 0;
int endy = 100;
uint64_t *sat;
uint64_t *square_sat;
uint16_t *src;

int x;
int y;

void init_vars() {
    size_t sat_height = (endy - starty) + 1;
    size_t sat_total_elements = sat_height * sat_linesize;
    sat = aligned_alloc(32, sat_total_elements * sizeof(uint64_t));
    square_sat = aligned_alloc(32, sat_total_elements * sizeof(uint64_t));

    size_t src_total_elements = sat_height * width;
    src = aligned_alloc(32, src_total_elements * sizeof(uint16_t));

    for (size_t i = 0; i < src_total_elements; i++) {
        src[i] = rand() & 0xFFFF;
    }

    for (size_t i = 0; i < sat_total_elements; i++) {
        sat[i] = 0;
        square_sat[i] = 0;
    }
}