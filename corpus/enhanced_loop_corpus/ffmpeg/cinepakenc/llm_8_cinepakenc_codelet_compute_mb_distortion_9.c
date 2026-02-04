#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *a_data[4];
extern int a_linesize[4];
extern uint8_t *b_data[4];
extern int b_linesize[4];
extern int x;
extern int y;
extern int p;
extern int d;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (p = 0; p < 3; p++) {
    for (y = 0; y < 8; y++)
        for (x = 0; x < 8; x++) {
            int idx_a = (x/2) + (y/2) * a_linesize[p];
            int idx_b = (x/2) + (y/2) * b_linesize[p];
            d = a_data[p][idx_a] - b_data[p][idx_b];
            ret += d * d;
            ret += d; // Additional arithmetic operation to increase computational intensity
        }
}
}
