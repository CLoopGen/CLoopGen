#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *ref;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ht_cnt = (height >> 4); ht_cnt--;) {
    for (int i = 0; i < 2; ++i) {
        ref += (3 * ref_stride);
        src += (2 * src_stride);
        {
            ref += (1 * ref_stride);
            src += (1 * src_stride);
        }
        ;
    }
    ;
    {
        src += (4 * src_stride);
        ref += (4 * ref_stride);
    }
    ;
    for (int j = 0; j < 3; ++j) {
        src++;
        ref++;
    }
}
}
