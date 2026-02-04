#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int zeros;
extern uint8_t *dst_end;
extern  uint8_t *src_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; src + i < src_end && dst + i < dst_end && i < 1024; i++) {
        uint8_t val = src[i];
        int local_zeros = zeros + i;
        if (local_zeros == 2) {
            if (val <= 3) {
                if (dst + i + 1 < dst_end) {
                    dst[i + 1] = 3;
                }
            }
            local_zeros = 0;
        }
        dst[i] = val;
        zeros = (val == 0) ? local_zeros + 1 : 0;
    }
}
