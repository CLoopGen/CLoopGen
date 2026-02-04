#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t left_sum[2][8];
extern uint16_t top_sum[2][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    uint16_t temp_top = (top_sum[1][i*2] * 181 + 128) >> 8;
    uint16_t temp_left = (left_sum[1][i*2] * 181 + 128) >> 8;
    top_sum[0][i*2] += temp_top;
    left_sum[0][i*2] += temp_left;
    if (i*2+1 < 8) {
        top_sum[0][i*2+1] += (top_sum[1][i*2+1] * 181 + 128) >> 8;
        left_sum[0][i*2+1] += (left_sum[1][i*2+1] * 181 + 128) >> 8;
    }
}
}
