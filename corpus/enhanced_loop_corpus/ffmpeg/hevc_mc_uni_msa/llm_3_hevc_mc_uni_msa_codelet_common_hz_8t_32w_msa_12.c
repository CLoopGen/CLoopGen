#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        // Variant 2: Indirect memory access using index array to simulate scattered read/write pattern
        static const int32_t offsets[] = {0, 1, 2, 3};
        int32_t idx0 = offsets[0], idx1 = offsets[1], idx2 = offsets[2], idx3 = offsets[3];

        // Use indirect addressing via calculated indices
        uint8_t *src_p0 = src + idx0 * src_stride;
        uint8_t *src_p1 = src + idx1 * src_stride;
        uint8_t *dst_p0 = dst + idx2 * dst_stride;
        uint8_t *dst_p1 = dst + idx3 * dst_stride;

        // Stride over source in non-unit steps (simulating blocked access)
        src_p0 += src_stride * 2;
        src_p1 += src_stride * 2;

        // Perform dummy operations mimicking actual computation on indirectly accessed data
        {
            {
            }
            ;
            {
            }
            ;
        }

        {
            {
            }
            ;
            {
            }
            ;
        }

        for (int k = 0; k < 4; ++k) {
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
            }
            ;
            {
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
        }

        // Update main pointers as before
        src += src_stride * 2;
        dst += dst_stride * 2;

        {
            {
            }
            ;
            {
            }
            ;
        }
        {
            {
            }
            ;
            {
            }
            ;
        }
    }
}
