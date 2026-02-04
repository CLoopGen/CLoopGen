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
for (ht_cnt = (height >> 2); ht_cnt--; ) {
    int update_src = (ht_cnt & 1);
    int update_ref = !(ht_cnt & 1);

    if (update_src) {
        src_ptr += (4 * src_stride);
    }

    if (update_ref) {
        ref_ptr += (4 * ref_stride);
    }

    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
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
