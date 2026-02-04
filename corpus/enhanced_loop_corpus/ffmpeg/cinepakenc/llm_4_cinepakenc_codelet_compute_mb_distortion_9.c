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
for (p = 1; p <= 2; p++) {
    if (a_data[p] == NULL || b_data[p] == NULL) continue;
    for (y = 0; y < 4 / 2; y++) {
        int ay_offset = y * a_linesize[p];
        int by_offset = y * b_linesize[p];
        for (x = 0; x < 4 / 2; x++) {
            d = a_data[p][x + ay_offset] - b_data[p][x + by_offset];
            ret += d * d;
        }
    }
}
}
