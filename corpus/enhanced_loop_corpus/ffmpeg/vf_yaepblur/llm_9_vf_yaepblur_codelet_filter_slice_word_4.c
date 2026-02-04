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
extern  uint16_t *src;
extern uint16_t *dst;
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
for (y = starty; y < endy; y++) {
    lower_y = y - radius < 0 ? 0 : y - radius;
    higher_y = y + radius + 1 > height ? height : y + radius + 1;
    dist_y = higher_y - lower_y;
    for (x = 0; x < width; x += 4) {
        lower_x = x - radius < 0 ? 0 : x - radius;
        higher_x = x + radius + 1 > width ? width : x + radius + 1;
        count = dist_y * (higher_x - lower_x);
        sum = sat[higher_y * sat_linesize + higher_x] - sat[higher_y * sat_linesize + lower_x] - sat[lower_y * sat_linesize + higher_x] + sat[lower_y * sat_linesize + lower_x];
        square_sum = square_sat[higher_y * sat_linesize + higher_x] - square_sat[higher_y * sat_linesize + lower_x] - square_sat[lower_y * sat_linesize + higher_x] + square_sat[lower_y * sat_linesize + lower_x];
        mean = sum / count;
        var = (square_sum - sum * sum / count) / count;
        
        // Unroll inner loop by factor of 4
        dst[y * dst_linesize + x] = (sigma * mean + var * src[y * src_linesize + x]) / (sigma + var);
        if (x + 1 < width)
            dst[y * dst_linesize + x + 1] = (sigma * mean + var * src[y * src_linesize + x + 1]) / (sigma + var);
        if (x + 2 < width)
            dst[y * dst_linesize + x + 2] = (sigma * mean + var * src[y * src_linesize + x + 2]) / (sigma + var);
        if (x + 3 < width)
            dst[y * dst_linesize + x + 3] = (sigma * mean + var * src[y * src_linesize + x + 3]) / (sigma + var);
    }
}
}
