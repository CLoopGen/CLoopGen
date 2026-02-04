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
    ret = 0;
    for (p = 1; p <= 2; p++) {
        uint8_t * restrict a_ptr = a_data[p];
        uint8_t * restrict b_ptr = b_data[p];
        int stride_a = a_linesize[p];
        int stride_b = b_linesize[p];
        int local_sum = 0;
        for (y = 0; y < 4 / 2; y++) {
            int base_a = y * stride_a;
            int base_b = y * stride_b;
            for (x = 0; x < 4 / 2; x++) {
                int d = a_ptr[base_a + x] - b_ptr[base_b + x];
                local_sum += d * d;
            }
        }
        ret += local_sum;
    }
}
