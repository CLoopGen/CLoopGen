#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int b0;
extern int b1;
extern int b2;
extern int16_t *b;
extern int16_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int stride = 1;
    for (x = 1; x < w2; x += stride) {
        unsigned int t_cur = temp[x];
        unsigned int t_nw = temp[x + w2 - 1];
        unsigned int t_ne = temp[x + w2];

        int scaled_diff = (int)(109 * (t_nw - t_ne) + 2048) >> 12;
        b2 = t_cur + ((int)(217 * (t_nw + t_ne) + 2048) >> 12) + scaled_diff;
        b1 = t_nw + ((int)(6497 * (b0 + b2) + 4096) >> 13);

        b[2 * x - 1] = (b1 + 1) >> 1;
        b[2 * x] = (b2 + 1) >> 1;

        b0 = (b2 + 1) >> 2;
        
        if (x % 3 == 0) {
            stride = 2;
        } else {
            stride = 1;
        }
    }
}
