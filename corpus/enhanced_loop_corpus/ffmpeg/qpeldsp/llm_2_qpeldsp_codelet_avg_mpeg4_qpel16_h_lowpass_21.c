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
        int j;
        uint8_t *dst_ptr = dst;
        uint8_t *src_ptr = src;
        for (j = 0; j < 17; j++) {
            if (j < 16) {
                int idx = ((src_ptr[j] + src_ptr[j+1]) * 20);
                if (j >= 1) idx -= (src_ptr[j-1] + src_ptr[j+2]) * 6;
                if (j >= 2) idx += (src_ptr[j-2] + src_ptr[j+3]) * 3;
                if (j >= 3) idx -= (src_ptr[j-3] + src_ptr[j+4]);
                idx = (idx + 16) >> 5;
                dst_ptr[j] = ((dst_ptr[j] + cm[idx] + 1) >> 1);
            } else {
                // Handle last few elements with boundary checks
                int k = j - 16;
                int base = 16 - k;
                int idx = ((src_ptr[base] + src_ptr[base+1]) * 20 - 
                          (src_ptr[base-1] + src_ptr[base+2]) * 6 + 
                          (src_ptr[base-2] + src_ptr[base+3]) * 3 - 
                          (src_ptr[base-3] + src_ptr[base+4])) + 16;
                idx >>= 5;
                dst_ptr[base] = ((dst_ptr[base] + cm[idx] + 1) >> 1);
            }
        }
        dst += dstStride;
        src += srcStride;
    }
}
