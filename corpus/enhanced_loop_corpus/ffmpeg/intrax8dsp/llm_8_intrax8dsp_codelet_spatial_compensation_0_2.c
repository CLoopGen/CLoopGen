#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t left_sum[2][8];
extern uint16_t top_sum[2][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    int idx = i % 8;
    top_sum[0][idx] += (top_sum[1][idx] * 181 + 128) >> 8;
    left_sum[0][idx] += (left_sum[1][idx] * 181 + 128) >> 8;
    top_sum[0][idx] -= (top_sum[0][idx] >> 4);
    left_sum[0][idx] -= (left_sum[0][idx] >> 4);
}
}
