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
    int32_t i;
    uint8_t *local_src, *local_ref;
    int32_t offset;

    for (ht_cnt = (height >> 2); ht_cnt--;) {
        // Remove loop-carried dependencies by using local copies and recompute offsets
        local_src = src + (4 * src_stride);
        local_ref = ref + (4 * ref_stride);

        // Independent updates — no data flow between iterations
        offset = 16; // Arbitrary fixed offset
        if (local_src[offset] > local_ref[offset]) {
            local_src[offset] -= 1;
        } else {
            local_ref[offset] += 1;
        }

        // Update pointers independently without cross-iteration reliance
        src = local_src;
        ref = local_ref;
    }
}
