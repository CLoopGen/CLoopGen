#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src_ptr;
extern int32_t src_stride;
extern uint8_t *ref_ptr;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ht_cnt = (height >> 2); ht_cnt--;) {
    uint8_t s0, s1, s2, s3;
    uint8_t r0, r1, r2, r3;

    // Consecutive memory access: load 4 rows of src and ref into local variables with stride
    s0 = src_ptr[0];
    s1 = src_ptr[src_stride];
    s2 = src_ptr[2 * src_stride];
    s3 = src_ptr[3 * src_stride];

    r0 = ref_ptr[0];
    r1 = ref_ptr[ref_stride];
    r2 = ref_ptr[2 * ref_stride];
    r3 = ref_ptr[3 * ref_stride];

    // Use the loaded values (simulating computation)
    s0 ^= r0; s1 ^= r1; s2 ^= r2; s3 ^= r3;

    // Advance pointers by 4 rows
    src_ptr += 4 * src_stride;
    ref_ptr += 4 * ref_stride;
}
}
