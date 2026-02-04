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
uint64_t temp_sum, temp_square_sum;
int prev_lower_y = 0, prev_higher_y = 0;
int cached_dist_y = 0;
for (y = starty; y < endy; y++) {
    lower_y = y - radius < 0 ? 0 : y - radius;
    higher_y = y + radius + 1 > height ? height : y + radius + 1;
    if (y == starty || lower_y != prev_lower_y || higher_y != prev_higher_y) {
        cached_dist_y = higher_y - lower_y;
        prev_lower_y = lower_y;
        prev_higher_y = higher_y;
    }
    dist_y = cached_dist_y;
    temp_sum = 0;
    temp_square_sum = 0;
    for (x = 0; x < width; x++) {
        lower_x = x - radius < 0 ? 0 : x - radius;
        higher_x = x + radius + 1 > width ? width : x + radius + 1;
        count = dist_y * (higher_x - lower_x);
        sum = sat[higher_y * sat_linesize + higher_x] - sat[higher_y * sat_linesize + lower_x] - sat[lower_y * sat_linesize + higher_x] + sat[lower_y * sat_linesize + lower_x];
        square_sum = square_sat[higher_y * sat_linesize + higher_x] - square_sat[higher_y * sat_linesize + lower_x] - square_sat[lower_y * sat_linesize + higher_x] + square_sat[lower_y * sat_linesize + lower_x];
        temp_sum += sum;
        temp_square_sum += square_sum;
        mean = sum / count;
        var = (square_sum - sum * sum / count) / count;
        dst[y * dst_linesize + x] = (sigma * mean + var * src[y * src_linesize + x]) / (sigma + var);
    }
    sum = temp_sum / width;
    square_sum = temp_square_sum / width;
}
}
