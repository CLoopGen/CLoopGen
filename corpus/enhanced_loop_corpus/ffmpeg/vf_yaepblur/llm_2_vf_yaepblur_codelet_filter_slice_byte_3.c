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
for (y = starty; y < endy; y++) {
    lower_y = y - radius < 0 ? 0 : y - radius;
    higher_y = y + radius + 1 > height ? height : y + radius + 1;
    dist_y = higher_y - lower_y;
    for (x = 0; x < width; x += 2) {  // Strided access: process two elements at a time
        lower_x = x - radius < 0 ? 0 : x - radius;
        higher_x = x + radius + 1 > width ? width : x + radius + 1;
        count = dist_y * (higher_x - lower_x);
        
        // First element (x)
        sum = sat[higher_y * sat_linesize + higher_x] - sat[higher_y * sat_linesize + lower_x] - sat[lower_y * sat_linesize + higher_x] + sat[lower_y * sat_linesize + lower_x];
        square_sum = square_sat[higher_y * sat_linesize + higher_x] - square_sat[higher_y * sat_linesize + lower_x] - square_sat[lower_y * sat_linesize + higher_x] + square_sat[lower_y * sat_linesize + lower_x];
        mean = sum / count;
        var = (square_sum - sum * sum / count) / count;
        dst[y * dst_linesize + x] = (sigma * mean + var * src[y * src_linesize + x]) / (sigma + var);

        // Second element (x+1), if within bounds
        if (x + 1 < width) {
            int x1 = x + 1;
            int lower_x1 = x1 - radius < 0 ? 0 : x1 - radius;
            int higher_x1 = x1 + radius + 1 > width ? width : x1 + radius + 1;
            int count1 = dist_y * (higher_x1 - lower_x1);

            uint64_t sum1 = sat[higher_y * sat_linesize + higher_x1] - sat[higher_y * sat_linesize + lower_x1] - sat[lower_y * sat_linesize + higher_x1] + sat[lower_y * sat_linesize + lower_x1];
            uint64_t square_sum1 = square_sat[higher_y * sat_linesize + higher_x1] - square_sat[higher_y * sat_linesize + lower_x1] - square_sat[lower_y * sat_linesize + higher_x1] + square_sat[lower_y * sat_linesize + lower_x1];
            uint64_t mean1 = sum1 / count1;
            uint64_t var1 = (square_sum1 - sum1 * sum1 / count1) / count1;

            dst[y * dst_linesize + x1] = (sigma * mean1 + var1 * src[y * src_linesize + x1]) / (sigma + var1);
        }
    }
}
}
