#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint16_t *src;
extern int angle;
extern  uint16_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t s = stride;
int local_size = size;
for (x = 0; x < local_size; x++) {
    int idx_base = ((x + 1) * angle);
    int idx = idx_base >> 5;
    int fact = idx_base & 31;
    if (fact) {
        uint16_t w0 = (32 - fact);
        uint16_t w1 = fact;
        for (y = 0; y < local_size; y++) {
            int ref_idx1 = y + idx + 1;
            int ref_idx2 = y + idx + 2;
            src[x + s * y] = (w0 * ref[ref_idx1] + w1 * ref[ref_idx2] + 16) >> 5;
        }
    } else {
        for (y = 0; y < local_size; y++) {
            src[x + s * y] = ref[y + idx + 1];
        }
    }
}
}
