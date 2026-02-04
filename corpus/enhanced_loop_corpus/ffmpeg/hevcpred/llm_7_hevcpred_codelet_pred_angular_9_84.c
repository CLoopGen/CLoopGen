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
uint16_t prev_val = 0;
for (x = 0; x < size; x++) {
    int idx = ((x + 1) * angle) >> 5;
    int fact = ((x + 1) * angle) & 31;
    for (y = 0; y < size; y++) {
        uint16_t current_ref_val;
        if (fact) {
            current_ref_val = ((32 - fact) * ref[y + idx + 1] + fact * ref[y + idx + 2] + 16) >> 5;
        } else {
            current_ref_val = ref[y + idx + 1];
        }
        src[(x) + stride * (y)] = current_ref_val ^ prev_val;
        prev_val = current_ref_val;
    }
}
}
