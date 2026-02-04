#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t left_sum[2][8];
extern uint16_t top_sum[2][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 1; j++) {
    for (i = 0; i < 8; i++) {
        top_sum[0][i] += (top_sum[1][i] * 181 + 128) >> 8;
        left_sum[0][i] += (left_sum[1][i] * 181 + 128) >> 8;
    }
}
}
