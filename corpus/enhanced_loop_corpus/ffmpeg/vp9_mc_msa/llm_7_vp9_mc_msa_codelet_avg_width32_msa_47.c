#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;
extern uint8_t *dst_dup;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependencies by making all updates independent
    // Use temporary variables to break WAW and WAR hazards
    uint8_t *src_base = src;
    uint8_t *dst_base = dst;
    uint8_t *dst_dup_base = dst_dup;
    int32_t s = 4 * src_stride;
    int32_t d = 4 * dst_stride;

    for (cnt = (height / 4); cnt--;) {
        int32_t offset = (height / 4 - 1 - cnt) * d; // Reverse index to remove dependence on previous iterations

        // Independent reads and writes — no inter-iteration dependencies
        uint8_t val0 = src_base[offset + 0];
        uint8_t val1 = src_base[offset + s/4];
        uint8_t val2 = src_base[offset + 2*s/4];
        uint8_t val3 = src_base[offset + 3*s/4];

        // Write to dst_dup without interfering with future reads
        dst_dup_base[offset + 0] = val0 ^ 0xFF;
        dst_dup_base[offset + d/4] = val1 ^ 0xFF;
        dst_dup_base[offset + 2*d/4] = val2 ^ 0xFF;
        dst_dup_base[offset + 3*d/4] = val3 ^ 0xFF;

        // Write to dst independently — no reliance on dst_dup or prior values
        dst_base[offset + 0] = val0 + 10;
        dst_base[offset + d/4] = val1 + 10;
        dst_base[offset + 2*d/4] = val2 + 10;
        dst_base[offset + 3*d/4] = val3 + 10;
    }

    // Bulk update of global pointers after full loop (no per-iteration side effects)
    src += (height / 4) * s;
    dst += (height / 4) * d;
    dst_dup += (height / 4) * d;
}
