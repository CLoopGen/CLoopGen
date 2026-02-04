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
for (x = 0; x < size; x += 2) {
    int idx_base = ((x + 1) * angle) >> 5;
    int fact_base = ((x + 1) * angle) & 31;
    int idx_next = ((x + 2) * angle) >> 5;
    int fact_next = ((x + 2) * angle) & 31;

    if (fact_base) {
        for (y = 0; y < size; y++) {
            src[(x) + stride * (y)] = ((32 - fact_base) * ref[y + idx_base + 1] + fact_base * ref[y + idx_base + 2] + 16) >> 5;
            if (x + 1 < size) {
                src[(x + 1) + stride * (y)] = ((32 - fact_next) * ref[y + idx_next + 1] + fact_next * ref[y + idx_next + 2] + 16) >> 5;
            }
        }
    } else {
        for (y = 0; y < size; y++) {
            src[(x) + stride * (y)] = ref[y + idx_base + 1];
            if (x + 1 < size) {
                if (fact_next) {
                    src[(x + 1) + stride * (y)] = ((32 - fact_next) * ref[y + idx_next + 1] + fact_next * ref[y + idx_next + 2] + 16) >> 5;
                } else {
                    src[(x + 1) + stride * (y)] = ref[y + idx_next + 1];
                }
            }
        }
    }
}
}
