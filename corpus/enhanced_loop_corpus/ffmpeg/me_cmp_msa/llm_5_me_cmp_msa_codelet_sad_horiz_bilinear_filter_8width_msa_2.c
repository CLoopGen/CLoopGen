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
    for (ht_cnt = (height >> 3); ht_cnt--;) {
        int phase1 = 1, phase2 = 1;

        if (phase1) {
            src += (4 * src_stride);
            ref += (4 * ref_stride);
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

        if ((height & 7) < 6) {
            src += (2 * src_stride);
            ref += (2 * ref_stride);
        } else {
            src += (4 * src_stride);
            ref += (4 * ref_stride);
        }

        {
            {
                {
                }
                {
                }
            }
            {
                {
                }
                {
                }
            }
        }
        ;

        if (phase2 && (ht_cnt & 1)) {
            src += (4 * src_stride);
            ref += (4 * ref_stride);
        } else {
            {
            }
            ;
            {
            }
            ;
        }
    }
}
