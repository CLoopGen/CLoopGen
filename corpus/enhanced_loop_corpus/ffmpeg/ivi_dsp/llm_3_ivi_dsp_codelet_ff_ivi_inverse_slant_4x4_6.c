#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *flags;
extern int i;
extern  int32_t *src;
extern int32_t *dst;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[4] = {0, 2, 1, 3}; // Indirect access pattern via index mapping
for (i = 0; i < 4; i++) {
    int mapped_i = indices[i]; // Remap iteration order
    if (flags[mapped_i]) {
        {
            t0 = (src[mapped_i]) - (src[mapped_i + 8]);
            t1 = (src[mapped_i]) + (src[mapped_i + 8]);
            t2 = (t0);
            ;
            t0 = (((src[mapped_i + 4]) + (src[mapped_i + 12]) * 2 + 2) >> 2) + (src[mapped_i + 4]);
            t3 = (((src[mapped_i + 4]) * 2 - (src[mapped_i + 12]) + 2) >> 2) - (src[mapped_i + 12]);
            t4 = (t0);
            ;
            t0 = (t1) - (t4);
            t1 = (t1) + (t4);
            t4 = (t0);
            ;
            t0 = (t2) - (t3);
            t2 = (t2) + (t3);
            t3 = (t0);
            ;
            dst[mapped_i] = (t1);
            dst[mapped_i + 4] = (t2);
            dst[mapped_i + 8] = (t3);
            dst[mapped_i + 12] = (t4);
        }
        ;
    } else {
        dst[mapped_i] = dst[mapped_i + 4] = dst[mapped_i + 8] = dst[mapped_i + 12] = 0;
    }
}
}
