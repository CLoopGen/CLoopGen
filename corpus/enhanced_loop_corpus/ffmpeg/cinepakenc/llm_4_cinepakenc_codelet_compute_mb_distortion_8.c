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
extern int d;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ret = 0;
    for (y = 0; y < 4; ++y) {
        for (x = 0; x < 4; ++x) {
            int idx_a = x + y * a_linesize[0];
            int idx_b = x + y * b_linesize[0];
            d = a_data[0][idx_a] - b_data[0][idx_b];
            if (d > 0) {
                ret += d * d;
            }
        }
    }
}
