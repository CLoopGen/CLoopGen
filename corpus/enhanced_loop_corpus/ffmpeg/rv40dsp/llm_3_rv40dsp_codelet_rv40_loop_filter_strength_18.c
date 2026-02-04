#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int step;
extern ptrdiff_t stride;
extern int sum_p1p2;
extern int sum_q1q2;
extern uint8_t *ptr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Increased Step Size (simulating wider jumps in memory)
    int wide_step = 2 * step; // Use a wider stride for access
    sum_p1p2 = 0;
    sum_q1q2 = 0;
    for (i = 0, ptr = src; i < 4; i++, ptr += stride) {
        sum_p1p2 += ptr[-1 * wide_step] - ptr[-2 * wide_step]; // Access spaced further apart
        sum_q1q2 += ptr[1 * wide_step] - ptr[2 * wide_step];
    }
}
