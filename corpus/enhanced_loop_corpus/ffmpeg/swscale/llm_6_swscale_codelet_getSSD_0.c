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
    uint64_t temp_ssd = 0;
    for (y = 0; y < h; y++) {
        uint8_t* s1 = &src1[y * stride1];
        uint8_t* s2 = &src2[y * stride2];
        for (x = 0; x < w; x += 4) {
            int d0 = s1[x + 0] - s2[x + 0];
            int d1 = s1[x + 1] - s2[x + 1];
            int d2 = s1[x + 2] - s2[x + 2];
            int d3 = s1[x + 3] - s2[x + 3];
            temp_ssd += d0 * d0 + d1 * d1 + d2 * d2 + d3 * d3;
        }
        for (; x < w; x++) {
            int d = s1[x] - s2[x];
            temp_ssd += d * d;
        }
    }
    ssd = temp_ssd;
}
