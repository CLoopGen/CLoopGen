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
for (x = 0; x < size; x += 2) {
    int idx1 = ((x + 1) * angle) >> 5;
    int fact1 = ((x + 1) * angle) & 31;
    int idx2 = ((x + 2) * angle) >> 5;
    int fact2 = ((x + 2) * angle) & 31;
    if (fact1) {
        for (y = 0; y < size; y++) {
            src[(x) + stride * (y)] = ((32 - fact1) * ref[y + idx1 + 1] + fact1 * ref[y + idx1 + 2] + 16) >> 5;
        }
    } else {
        for (y = 0; y < size; y++)
            src[(x) + stride * (y)] = ref[y + idx1 + 1];
    }
    if (x + 1 < size) {
        if (fact2) {
            for (y = 0; y < size; y++) {
                src[(x + 1) + stride * (y)] = ((32 - fact2) * ref[y + idx2 + 1] + fact2 * ref[y + idx2 + 2] + 16) >> 5;
            }
        } else {
            for (y = 0; y < size; y++)
                src[(x + 1) + stride * (y)] = ref[y + idx2 + 1];
        }
    }
}
}
