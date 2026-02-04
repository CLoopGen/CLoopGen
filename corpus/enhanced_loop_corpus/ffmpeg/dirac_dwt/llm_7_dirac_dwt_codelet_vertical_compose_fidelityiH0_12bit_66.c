#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;
extern int32_t *b3;
extern int32_t *b4;
extern int32_t *b5;
extern int32_t *b6;
extern int32_t *b7;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t sum_b0b7, sum_b1b6, sum_b2b5, sum_b3b4;
    for (i = 0; i < width; i += 4) {
        if (i + 3 < width) {
            sum_b0b7 = (b0[i] + (unsigned int)b7[i]) + (b0[i+1] + (unsigned int)b7[i+1]) + (b0[i+2] + (unsigned int)b7[i+2]) + (b0[i+3] + (unsigned int)b7[i+3]);
            sum_b1b6 = (b1[i] + (unsigned int)b6[i]) + (b1[i+1] + (unsigned int)b6[i+1]) + (b2[i+2] + (unsigned int)b5[i+2]) + (b2[i+3] + (unsigned int)b5[i+3]); 
            sum_b2b5 = (b2[i] + (unsigned int)b5[i]) + (b2[i+1] + (unsigned int)b5[i+1]) + (b1[i+2] + (unsigned int)b6[i+2]) + (b1[i+3] + (unsigned int)b6[i+3]); 
            sum_b3b4 = (b3[i] + (unsigned int)b4[i]) + (b3[i+1] + (unsigned int)b4[i+1]) + (b3[i+2] + (unsigned int)b4[i+2]) + (b3[i+3] + (unsigned int)b4[i+3]);

            dst[i]   += ((-2 * (b0[i]   + (unsigned int)b7[i])   + 10 * (b1[i]   + (unsigned int)b6[i])   - 25 * (b2[i]   + (unsigned int)b5[i])   + 81 * (b3[i]   + (unsigned int)b4[i])   + 128) >> 8);
            dst[i+1] += ((-2 * (b0[i+1] + (unsigned int)b7[i+1]) + 10 * (b1[i+1] + (unsigned int)b6[i+1]) - 25 * (b2[i+1] + (unsigned int)b5[i+1]) + 81 * (b3[i+1] + (unsigned int)b4[i+1]) + 128) >> 8);
            dst[i+2] += ((-2 * (b0[i+2] + (unsigned int)b7[i+2]) + 10 * (b1[i+2] + (unsigned int)b6[i+2]) - 25 * (b2[i+2] + (unsigned int)b5[i+2]) + 81 * (b3[i+2] + (unsigned int)b4[i+2]) + 128) >> 8);
            dst[i+3] += ((-2 * (b0[i+3] + (unsigned int)b7[i+3]) + 10 * (b1[i+3] + (unsigned int)b6[i+3]) - 25 * (b2[i+3] + (unsigned int)b5[i+3]) + 81 * (b3[i+3] + (unsigned int)b4[i+3]) + 128) >> 8);
        } else {
            for (; i < width; i++) {
                dst[i] = ((unsigned int)dst[i] + ((int)(-2 * (b0[i] + (unsigned int)b7[i]) + 10 * (b1[i] + (unsigned int)b6[i]) - 25 * (b2[i] + (unsigned int)b5[i]) + 81 * (b3[i] + (unsigned int)b4[i]) + 128) >> 8));
            }
        }
    }
}
