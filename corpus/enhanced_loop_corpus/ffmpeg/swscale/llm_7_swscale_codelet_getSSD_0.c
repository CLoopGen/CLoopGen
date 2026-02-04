#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int stride1;
extern int stride2;
extern int w;
extern int h;
extern int x;
extern int y;
extern uint64_t ssd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssd = 0;
    uint64_t local_ssd = 0;
    int chunk = 8;
    for (y = 0; y < h; y += chunk) {
        uint64_t block_sum = 0;
        int y_end = (y + chunk > h) ? h : y + chunk;
        for (int y_idx = y; y_idx < y_end; y_idx++) {
            for (x = 0; x < w; x++) {
                int d = src1[x + y_idx * stride1] - src2[x + y_idx * stride2];
                local_ssd += d * d;
            }
        }
        block_sum += local_ssd;
        ssd += block_sum;
    }
}
