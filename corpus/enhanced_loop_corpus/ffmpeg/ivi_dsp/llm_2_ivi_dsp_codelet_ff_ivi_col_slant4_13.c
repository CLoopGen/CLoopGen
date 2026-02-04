#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *in;
extern int16_t *out;
extern ptrdiff_t pitch;
extern  uint8_t *flags;
extern int i;
extern int row2;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    if (flags[i]) {
        {
            ptrdiff_t idx = i * 16; // Strided access with offset based on loop index
            t0 = (in[idx + 0]) - (in[idx + 8]);
            t1 = (in[idx + 0]) + (in[idx + 8]);
            t2 = (t0);
            ;
            t0 = (((in[idx + 4]) + (in[idx + 12]) * 2 + 2) >> 2) + (in[idx + 4]);
            t3 = (((in[idx + 4]) * 2 - (in[idx + 12]) + 2) >> 2) - (in[idx + 12]);
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
            out[0] = (((t1) + 1) >> 1);
            out[pitch] = (((t2) + 1) >> 1);
            out[row2] = (((t3) + 1) >> 1);
            out[row2 + pitch] = (((t4) + 1) >> 1);
        }
        ;
    } else {
        out[0] = out[pitch] = out[row2] = out[row2 + pitch] = 0;
    }
    in += 16; // Adjust pointer step to match strided input access
    out++;
}
}
