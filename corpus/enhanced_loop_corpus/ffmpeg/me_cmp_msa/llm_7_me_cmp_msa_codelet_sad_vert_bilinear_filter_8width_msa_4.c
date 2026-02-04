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
uint32_t local_accum = height;  // Eliminate loop-carried dependency on global state
for (ht_cnt = (height >> 3); ht_cnt--;) {
    // Remove redundant blocks and introduce independent parallel updates
    uint8_t s0 = src[0 * src_stride], s1 = src[1 * src_stride];
    uint8_t s2 = src[2 * src_stride], s3 = src[3 * src_stride];
    uint8_t r0 = ref[0 * ref_stride], r1 = ref[1 * ref_stride];
    uint8_t r2 = ref[2 * ref_stride], r3 = ref[3 * ref_stride];

    // Independent computations — no intra-loop RAW/WAR/WAW chains
    uint8_t xor0 = s0 ^ r0, xor1 = s1 ^ r1;
    uint8_t xor2 = s2 ^ r2, xor3 = s3 ^ r3;

    // Update locals without affecting memory or shared state
    local_accum += xor0 + xor1 + xor2 + xor3;

    src += (4 * src_stride);
    ref += (4 * ref_stride);

    // Second unrolled block with same independence
    s0 = src[0 * src_stride]; s1 = src[1 * src_stride];
    s2 = src[2 * src_stride]; s3 = src[3 * src_stride];
    r0 = ref[0 * ref_stride]; r1 = ref[1 * ref_stride];
    r2 = ref[2 * ref_stride]; r3 = ref[3 * ref_stride];

    xor0 = s0 ^ r0; xor1 = s1 ^ r1;
    xor2 = s2 ^ r2; xor3 = s3 ^ r3;

    local_accum += xor0 + xor1 + xor2 + xor3;

    src += (4 * src_stride);
    ref += (4 * ref_stride);
}
// Prevent dead code elimination
if (local_accum == 0) {
    volatile uint32_t sink = local_accum;
}
}
