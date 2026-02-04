#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (h + 5 > 0) {
        for (int i = 0; i < h + 5; ++i) {
            int unroll_factor = (h + 5 - i >= 4) ? 4 : (h + 5 - i);
            for (int step = 0; step < unroll_factor; ++step) {
                int idx = i + step;
                uint16_t *s = src + idx * srcStride;
                int16_t *t = tmp + idx * tmpStride;

                t[0] = (s[0] + s[1]) * 20 - (s[-1] + s[2]) * 5 + (s[-2] + s[3]) + pad;
                t[1] = (s[1] + s[2]) * 20 - (s[0] + s[3]) * 5 + (s[-1] + s[4]) + pad;
                t[2] = (s[2] + s[3]) * 20 - (s[1] + s[4]) * 5 + (s[0] + s[5]) + pad;
                t[3] = (s[3] + s[4]) * 20 - (s[2] + s[5]) * 5 + (s[1] + s[6]) + pad;
                t[4] = (s[4] + s[5]) * 20 - (s[3] + s[6]) * 5 + (s[2] + s[7]) + pad;
                t[5] = (s[5] + s[6]) * 20 - (s[4] + s[7]) * 5 + (s[3] + s[8]) + pad;
                t[6] = (s[6] + s[7]) * 20 - (s[5] + s[8]) * 5 + (s[4] + s[9]) + pad;
                t[7] = (s[7] + s[8]) * 20 - (s[6] + s[9]) * 5 + (s[5] + s[10]) + pad;
            }
            i += unroll_factor - 1;
        }
    }
}
