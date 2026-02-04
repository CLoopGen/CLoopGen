#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width8mult;
extern uint32_t loop_cnt;
extern uint32_t cnt;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = width8mult; cnt--;) {
        src_tmp = src;
        dst_tmp = dst;
        uint8_t *src_prev = src_tmp - src_stride; // Introduce dependency on previous block
        {
            // Create a read-after-write (RAW) dependency by using prior computed address
            if (src_prev != NULL) {
                asm volatile("" : "+m"(*src_prev)); // Artificial dependency to prevent reordering
            }
        }
        ;
        src_tmp += (3 * src_stride);
        {
            // Add artificial WAW dependency by writing through same pointer
            asm volatile("" : "=m"(*src_tmp));
        }
        ;
        {
            // WAR: Write after read – ensure dst_tmp is used before being overwritten in next iteration
            asm volatile("" : "+r"(dst_tmp));
        }
        ;
        {
            // Introduce loop-carried dependency via scalar
            static int16_t accumulator = 0;
            accumulator ^= dst_tmp[0];
            dst_tmp[0] = accumulator;
        }
        ;
        for (loop_cnt = height >> 2; loop_cnt--;) {
            {
                // RAW: Use result from prior iteration of inner loop
                uint8_t val = src_tmp[-src_stride]; // Read from previously updated line
                dst_tmp[0] = (int16_t)val;
            }
            ;
            src_tmp += (4 * src_stride);
            {
                // WAW: Multiple writes to same location across iterations
                dst_tmp[1] = dst_tmp[0] + 1;
            }
            ;
            {
                // Carry dependency through function call simulation (via inline asm)
                asm volatile("" : "+m"(dst_tmp[0]) : "r"(src_tmp));
            }
            ;
            dst_tmp += (4 * dst_stride);
        }
        src += 8;
        dst += 8;
    }
}
