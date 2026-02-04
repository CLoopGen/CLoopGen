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
uint8_t *src;
uint8_t *dst;

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
    sat = aligned_alloc(64, sizeof(uint64_t) * sat_linesize * (height + 1));
    square_sat = aligned_alloc(64, sizeof(uint64_t) * sat_linesize * (height + 1));
    src = aligned_alloc(64, sizeof(uint8_t) * src_linesize * height);
    dst = aligned_alloc(64, sizeof(uint8_t) * dst_linesize * height);

    memset(sat, 0, sizeof(uint64_t) * sat_linesize * (height + 1));
    memset(square_sat, 0, sizeof(uint64_t) * sat_linesize * (height + 1));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            src[i * src_linesize + j] = rand() % 256;
        }
    }

    for (int i = 1; i <= height; i++) {
        uint64_t row_prefix = 0;
        uint64_t row_square_prefix = 0;
        for (int j = 1; j <= width; j++) {
            uint64_t val = src[(i-1) * src_linesize + (j-1)];
            row_prefix += val;
            row_square_prefix += val * val;
            sat[i * sat_linesize + j] = sat[(i-1) * sat_linesize + j] + row_prefix;
            square_sat[i * sat_linesize + j] = square_sat[(i-1) * sat_linesize + j] + row_square_prefix;
        }
    }

    starty = radius;
    endy = height - radius;
    if (starty >= endy) {
        starty = 0;
        endy = height;
    }
}