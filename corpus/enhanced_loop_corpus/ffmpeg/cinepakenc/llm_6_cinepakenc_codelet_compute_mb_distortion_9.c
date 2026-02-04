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
    int temp_ret = 0;
    for (p = 1; p <= 2; p++) {
        int linesize_a = a_linesize[p];
        int linesize_b = b_linesize[p];
        uint8_t *data_a = a_data[p];
        uint8_t *data_b = b_data[p];
        for (y = 0; y < 4 / 2; y++) {
            for (x = 0; x < 4 / 2; x++) {
                int idx_a = x + y * linesize_a;
                int idx_b = x + y * linesize_b;
                int diff = data_a[idx_a] - data_b[idx_b];
                temp_ret += diff * diff;
            }
        }
    }
    ret += temp_ret;
}
