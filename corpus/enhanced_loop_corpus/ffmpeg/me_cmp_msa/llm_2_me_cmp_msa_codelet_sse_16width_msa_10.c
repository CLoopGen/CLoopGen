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
        // Unroll the loop but change memory access to consecutive loading via pointer increments
        // Simulate processing four rows by incrementing pointers once per iteration with stride skip
        uint8_t *s0 = src_ptr;
        uint8_t *r0 = ref_ptr;
        uint8_t *s1 = s0 + src_stride;
        uint8_t *r1 = r0 + ref_stride;
        uint8_t *s2 = s1 + src_stride;
        uint8_t *r2 = r1 + ref_stride;
        uint8_t *s3 = s2 + src_stride;
        uint8_t *r3 = r2 + ref_stride;

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

        src_ptr = s3 + src_stride;
        ref_ptr = r3 + ref_stride;
    }
}
