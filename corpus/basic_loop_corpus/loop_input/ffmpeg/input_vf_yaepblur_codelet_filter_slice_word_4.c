#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int width = 1024;
int height = 1024;
int src_linesize = 1024;
int dst_linesize = 1024;
int sat_linesize = 1025;
int sigma = 16;
int radius = 3;
uint64_t *sat;
uint64_t *square_sat;
uint16_t *src;
uint16_t *dst;
int starty = 0;
int endy = 1024;
int x;
int y;
int lower_x;
int higher_x;
int lower_y;
int higher_y;
int dist_y;
int count;
uint64_t sum;
uint64_t square_sum;
uint64_t mean;
uint64_t var;

void init_vars() {
    const size_t src_size = (size_t)height * src_linesize * sizeof(uint16_t);
    const size_t dst_size = (size_t)height * dst_linesize * sizeof(uint16_t);
    const size_t sat_height = (size_t)height + 1;
    const size_t sat_width = (size_t)width + 1;
    const size_t sat_elem_count = sat_height * sat_width;
    const size_t sat_size = sat_elem_count * sizeof(uint64_t);

    src = (uint16_t*)calloc(height, src_linesize * sizeof(uint16_t));
    dst = (uint16_t*)calloc(height, dst_linesize * sizeof(uint16_t));
    sat = (uint64_t*)calloc(sat_elem_count, sizeof(uint64_t));
    square_sat = (uint64_t*)calloc(sat_elem_count, sizeof(uint64_t));

    if (!src || !dst || !sat || !square_sat) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            src[i * src_linesize + j] = (uint16_t)(rand() & 0x3FF); 
        }
    }

    for (size_t i = 1; i <= height; i++) {
        uint64_t row_prefix = 0;
        uint64_t square_row_prefix = 0;
        for (size_t j = 1; j <= width; j++) {
            uint64_t val = src[(i-1) * src_linesize + (j-1)];
            row_prefix += val;
            square_row_prefix += val * val;
            sat[i * sat_linesize + j] = sat[(i-1) * sat_linesize + j] + row_prefix;
            square_sat[i * sat_linesize + j] = square_sat[(i-1) * sat_linesize + j] + square_row_prefix;
        }
    }

    starty = radius;
    endy = height - radius;
    if (starty >= endy) {
        starty = 0;
        endy = height;
    }
}