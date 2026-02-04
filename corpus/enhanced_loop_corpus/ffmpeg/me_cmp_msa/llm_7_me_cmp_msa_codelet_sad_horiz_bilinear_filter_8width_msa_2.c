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
int32_t local_ht_cnt = (height >> 3);
uint8_t *src_copy = src;
uint8_t *ref_copy = ref;
int i;

// Eliminate loop-carried dependencies by unrolling and reordering operations
// All updates happen at end — no state carried between iterations

while (local_ht_cnt >= 2) {
    // Process two "iterations" worth of work without updating src/ref until end
    uint8_t val1, val2;

    // First part (simulates first half of original loop body)
    val1 = src_copy[0];
    val2 = ref_copy[0];
    src_copy += (4 * src_stride);
    ref_copy += (4 * ref_stride);

    // Second part (simulates second half), no dependency on prior pointer updates
    val1 ^= src_copy[0];
    val2 ^= ref_copy[0];
    src_copy += (4 * src_stride);
    ref_copy += (4 * ref_stride);

    // Fold results into dummy computation to prevent dead code elimination
    if (val1 != val2) {
        val1 ^= 0x55;
    }

    local_ht_cnt -= 2;
}

// Handle remaining iteration if any
if (local_ht_cnt > 0) {
    uint8_t val = src_copy[0] ^ ref_copy[0];
    src_copy += (4 * src_stride);
    ref_copy += (4 * ref_stride);
    if (val & 1) {
        src_copy[0] ^= val;
    }
    src_copy += (4 * src_stride);
    ref_copy += (4 * ref_stride);
}

// Write back final values to maintain observable behavior
src = src_copy;
ref = ref_copy;
}
