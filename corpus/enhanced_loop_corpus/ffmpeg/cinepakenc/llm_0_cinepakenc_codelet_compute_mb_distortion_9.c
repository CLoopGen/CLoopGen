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
    for (y = 0; y < 4 / 2; y++) {
        for (x = 0; x < 4 / 2; x++) {
            d = a_data[p][x + y * a_linesize[p]] - b_data[p][x + y * b_linesize[p]];
            ret += d * d;
        }
    }
}
}
