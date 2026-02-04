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
for (p = 1; p <= 2; p += 2) {
    for (y = 0; y < 2; y++) {
        int base_a = y * a_linesize[p];
        int base_b = y * b_linesize[p];
        for (x = 0; x < 2; x += 2) {
            int val_a = a_data[p][base_a + x];
            int val_b = b_data[p][base_b + x];
            int diff1 = val_a - val_b;
            ret += diff1 * diff1;
            if (x + 1 < 2 && y + 1 < 2) {
                int diag_a = a_data[p][base_a + x + a_linesize[p] + 1];
                int diag_b = b_data[p][base_b + x + b_linesize[p] + 1];
                int diff2 = diag_a - diag_b;
                ret += diff2 * diff2;
            }
        }
    }
}
}
