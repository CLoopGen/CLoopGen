#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src_ptr;
extern int32_t src_stride;
extern uint8_t *ref_ptr;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ht_cnt = (height >> 3); ht_cnt--;) {
        for (int outer_step = 0; outer_step < 2; ++outer_step) {
            {
            }
            ;
            {
            }
            ;
            src_ptr += (4 * src_stride);
            {
            }
            ;
            ref_ptr += (4 * ref_stride);
            {
            }
            ;
            {
            }
            ;
            {
            }
            ;
        }
    }
}
