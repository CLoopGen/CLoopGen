#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        uint8_t *src_base = src;
        uint8_t *dst_base = dst;
        const int cm_offset = 16;
        const int shift = 5;

        for (int j = 0; j < 15; j++) {
            int sum0 = src_base[j] + src_base[j + 1];
            int sum1 = src_base[j - (j > 0 ? 1 : 0)] + src_base[j + 2]; // Avoid negative index
            int sum2 = src_base[(j >= 2) ? j - 2 : 0] + src_base[j + 3];
            int sum3 = src_base[(j >= 3) ? j - 3 : 0] + src_base[(j + 4 < 17) ? j + 4 : 16];

            int val;
            if (j == 0) {
                val = (((sum0)*20 - (src_base[0] + src_base[2])*6 + (src_base[1] + src_base[3])*3 - (src_base[2] + src_base[4])) + cm_offset);
            } else if (j < 14) {
                val = (((sum0)*20 
                       - (src_base[j-1] + src_base[j+2])*6 
                       + (src_base[j-2] + src_base[j+3])*3 
                       - (src_base[j-3] + src_base[j+4])) + cm_offset);
            } else {
                // Last few elements use original hardcoded logic to preserve correctness
                val = (((src_base[j] + src_base[j+1])*20 
                       - (src_base[j-1] + src_base[j+2])*6 
                       + (src_base[j-2] + src_base[j+3])*3 
                       - (src_base[j-3] + src_base[(j+4 <= 16) ? j+4 : 16])) + cm_offset);
            }
            dst_base[j] = cm[val >> shift];
        }

        // Handle last element separately due to asymmetric taps
        dst_base[15] = cm[(((src_base[15] + src_base[16]) * 20 
                          - (src_base[14] + src_base[16]) * 6 
                          + (src_base[13] + src_base[15]) * 3 
                          - (src_base[12] + src_base[14])) + cm_offset) >> shift];

        dst += dstStride;
        src += srcStride;
    }
}
