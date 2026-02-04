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
    for (ht_cnt = (height >> 2); ht_cnt--;) {
        uint8_t s0, s1, s2, s3;
        uint8_t r0, r1, r2, r3;

        // Consecutive memory access: unroll the 4-row access and read elements sequentially from each row
        for (int i = 0; i < 4; ++i) {
            s0 = src[i * src_stride];
            s1 = src[i * src_stride + 1];
            s2 = src[i * src_stride + 2];
            s3 = src[i * src_stride + 3];

            r0 = ref[i * ref_stride];
            r1 = ref[i * ref_stride + 1];
            r2 = ref[i * ref_stride + 2];
            r3 = ref[i * ref_stride + 3];

            // Dummy operations to prevent optimization away
            __asm__ volatile("" : "+r"(s0), "+r"(r0));
            __asm__ volatile("" : "+r"(s1), "+r"(r1));
            __asm__ volatile("" : "+r"(s2), "+r"(r2));
            __asm__ volatile("" : "+r"(s3), "+r"(r3));
        }

        ref += (4 * ref_stride);
        src += (4 * src_stride);
    }
}
