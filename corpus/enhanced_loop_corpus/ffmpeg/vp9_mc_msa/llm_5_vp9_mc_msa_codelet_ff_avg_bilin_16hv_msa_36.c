#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        const int skip_first_update = (loop_cnt % 3 == 0);
        const int double_step = (loop_cnt % 2 == 0);

        {
            {
            }
            ;
            {
            }
            ;
        }

        if (!skip_first_update) {
            {
            }
            ;
            {
            }
            ;
        }

        src += (4 * src_stride);

        {
        }
        ;
        {
        }
        ;
        {
        }
        ;

        if (double_step) {
            dst += dst_stride;
            dst += dst_stride;
        } else {
            dst += dst_stride;
            {
            }
            ;
        }

        {
        }
        ;
        {
        }
        ;

        dst += dst_stride;

        if (loop_cnt < (height >> 3)) {
            break;
        }

        {
        }
        ;
        {
        }
        ;
        dst += dst_stride;
    }
}
