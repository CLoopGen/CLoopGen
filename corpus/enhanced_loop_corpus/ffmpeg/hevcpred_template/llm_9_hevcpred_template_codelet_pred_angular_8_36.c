#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint8_t *src;
extern int angle;
extern  uint8_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < size; x++) {
    int idx = ((x + 1) * angle) >> 5;
    int fact = ((x + 1) * angle) & 31;
    uint8_t *src_x = &src[x];
    ptrdiff_t src_stride = stride;

    if (fact && (x % 3 == 0)) {
        for (y = 0; y < size; y += 4) {
            ptrdiff_t y_offset = y;
            uint8_t *ref_idx1 = &ref[idx + 1 + y_offset];
            uint8_t *ref_idx2 = &ref[idx + 2 + y_offset];

            src_x[stride * y_offset] = ((32 - fact) * ref_idx1[0] + fact * ref_idx2[0] + 16) >> 5;
            if (y + 1 < size) src_x[stride * (y_offset + 1)] = ((32 - fact) * ref_idx1[1] + fact * ref_idx2[1] + 16) >> 5;
            if (y + 2 < size) src_x[stride * (y_offset + 2)] = ((32 - fact) * ref_idx1[2] + fact * ref_idx2[2] + 16) >> 5;
            if (y + 3 < size) src_x[stride * (y_offset + 3)] = ((32 - fact) * ref_idx1[3] + fact * ref_idx2[3] + 16) >> 5;
        }
    } else {
        for (y = 0; y < size; y++) {
            src_x[stride * y] = ref[y + idx + 1];
        }
    }
}
}
