#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int width;
extern  int height;
extern  int src_linesize;
extern  int dst_linesize;
extern  int sat_linesize;
extern  int sigma;
extern  int radius;
extern uint64_t *sat;
extern uint64_t *square_sat;
extern  uint8_t *src;
extern uint8_t *dst;
extern  int starty;
extern  int endy;
extern int x;
extern int y;
extern int lower_x;
extern int higher_x;
extern int lower_y;
extern int higher_y;
extern int dist_y;
extern int count;
extern uint64_t sum;
extern uint64_t square_sum;
extern uint64_t mean;
extern uint64_t var;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to use row pointers (consecutive access)
for (y = starty; y < endy; y++) {
    lower_y = y - radius < 0 ? 0 : y - radius;
    higher_y = y + radius + 1 > height ? height : y + radius + 1;
    dist_y = higher_y - lower_y;

    // Precompute base pointers for current and range rows in SAT tables
    uint64_t *sat_higher_row = &sat[higher_y * sat_linesize];
    uint64_t *sat_lower_row = &sat[lower_y * sat_linesize];
    uint64_t *square_sat_higher_row = &square_sat[higher_y * sat_linesize];
    uint64_t *square_sat_lower_row = &square_sat[lower_y * sat_linesize];
    uint8_t *dst_row = &dst[y * dst_linesize];
    uint8_t *src_row = &src[y * src_linesize];

    for (x = 0; x < width; x++) {
        lower_x = x - radius < 0 ? 0 : x - radius;
        higher_x = x + radius + 1 > width ? width : x + radius + 1;

        // Use precomputed row pointers for more consecutive-like access
        count = dist_y * (higher_x - lower_x);
        sum = sat_higher_row[higher_x] - sat_higher_row[lower_x] - sat_lower_row[higher_x] + sat_lower_row[lower_x];
        square_sum = square_sat_higher_row[higher_x] - square_sat_higher_row[lower_x] - square_sat_lower_row[higher_x] + square_sat_lower_row[lower_x];
        mean = sum / count;
        var = (square_sum - sum * sum / count) / count;
        dst_row[x] = (sigma * mean + var * src_row[x]) / (sigma + var);
    }
}
}
