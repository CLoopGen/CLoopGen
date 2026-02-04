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
for (x = 0; x < size; x++) {
    int idx = ((x + 1) * angle) >> 5;
    int fact = ((x + 1) * angle) & 31;
    uint16_t temp_val;
    if (fact) {
        for (y = 0; y < size; y++) {
            int ref_idx1 = y + idx + 1;
            int ref_idx2 = y + idx + 2;
            temp_val = ((32 - fact) * ref[ref_idx1] + fact * ref[ref_idx2] + 16) >> 5;
            src[(x) + stride * (y)] = temp_val;
        }
    } else {
        for (y = 0; y < size; y++) {
            int ref_idx = y + idx + 1;
            temp_val = ref[ref_idx];
            src[(x) + stride * (y)] = temp_val;
        }
    }
}
}
