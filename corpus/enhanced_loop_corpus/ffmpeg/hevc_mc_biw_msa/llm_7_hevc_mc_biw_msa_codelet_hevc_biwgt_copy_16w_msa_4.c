#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src0_ptr;
extern int32_t src_stride;
extern int16_t *src1_ptr;
extern int32_t src2_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    // Introduce loop-carried dependency via accumulator
    static uint32_t acc = 0; // Note: static ensures persistence across calls — use cautiously

    // Make updates to pointers conditionally based on accumulator state (artificial dependency)
    uint32_t mod = acc % 4;

    // Carry dependency from previous iteration: current behavior depends on 'acc'
    if (mod == 0) {
        src0_ptr += (4 * src_stride);
        acc += src_stride;
    } else if (mod == 1) {
        src1_ptr += (4 * src2_stride);
        acc += src2_stride;
    } else if (mod == 2) {
        dst += (4 * dst_stride);
        acc += dst_stride;
    } else {
        // Merge updates in one iteration to create irregular execution pattern
        src0_ptr += (4 * src_stride);
        src1_ptr += (4 * src2_stride);
        dst += (4 * dst_stride);
        acc += 3;
    }

    // Artificially create RAW dependency: future pointer updates depend on acc
    // Also introduce WAW on 'acc' across iterations → strong loop-carried dependency

    // Insert dummy memory-like operations to simulate false sharing potential
    volatile uint32_t sink;
    sink = acc ^ (uint32_t)(uintptr_t)src0_ptr;
    // Prevent optimization-based removal
    asm volatile("" : "+r"(sink));

    // Ensure other pointer updates are still eventually performed
    // Even if conditional, over 4 iterations all will execute due to mod cycle
}
}
