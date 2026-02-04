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
    for (ht_cnt = (height >> 2); ht_cnt--;) {
        if (ht_cnt % 2 == 0) {
            src_ptr += src_stride * 2;
            ref_ptr += ref_stride * 2;
            {
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
            ;
            src_ptr += src_stride;
            ref_ptr += ref_stride;
        } else {
            src_ptr += src_stride;
            ref_ptr += ref_stride;
        }
        {
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
        ;
        if (ht_cnt > (height >> 3)) {
            src_ptr += src_stride;
            ref_ptr += ref_stride;
        }
        {
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
        ;
    }
}
