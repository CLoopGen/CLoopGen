#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src_r;
extern uint8_t *src_g;
extern uint8_t *src_b;
extern ptrdiff_t linesize_r;
extern ptrdiff_t linesize_g;
extern ptrdiff_t linesize_b;
extern int width;
extern int height;
extern uint8_t r;
extern uint8_t g;
extern uint8_t b;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    for (j = 0; j < height; j++) {
        uint8_t *r_ptr = src_r;
        uint8_t *g_ptr = src_g;
        uint8_t *b_ptr = src_b;
        for (i = 0; i < width - 1; i += 2) {
            // Process two pixels at once to promote consecutive access and potential vectorization
            uint8_t r0 = r_ptr[0], g0 = g_ptr[0], b0 = b_ptr[0];
            uint8_t r1 = r_ptr[1], g1 = g_ptr[1], b1 = b_ptr[1];

            r_ptr[0] = r0 + g0 - 128;
            b_ptr[0] = b0 + g0 - 128;
            r_ptr[1] = r1 + g1 - 128;
            b_ptr[1] = b1 + g1 - 128;

            r_ptr += 2;
            g_ptr += 2;
            b_ptr += 2;
        }
        // Handle odd-width case
        if (i < width) {
            r = *r_ptr;
            g = *g_ptr;
            b = *b_ptr;
            *r_ptr = r + g - 128;
            *b_ptr = b + g - 128;
        }
        src_r += linesize_r;
        src_g += linesize_g;
        src_b += linesize_b;
    }
}
