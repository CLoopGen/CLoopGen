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

    if (fact1 || (x + 1 < size && fact2)) {
        for (y = 0; y < size; y++) {
            int addr1 = x + stride * y;
            int addr2 = (x + 1) + stride * y;
            int ref_idx1a = y + idx1 + 1;
            int ref_idx1b = y + idx1 + 2;
            int ref_idx2a = y + idx2 + 1;
            int ref_idx2b = y + idx2 + 2;

            if (x < size) {
                if (fact1) {
                    src[addr1] = ((32 - fact1) * ref[ref_idx1a] + fact1 * ref[ref_idx1b] + 16) >> 5;
                } else {
                    src[addr1] = ref[ref_idx1a];
                }
            }

            if (x + 1 < size) {
                if (fact2) {
                    src[addr2] = ((32 - fact2) * ref[ref_idx2a] + fact2 * ref[ref_idx2b] + 16) >> 5;
                } else {
                    src[addr2] = ref[ref_idx2a];
                }
            }
        }
    } else {
        for (y = 0; y < size; y++) {
            int addr1 = x + stride * y;
            int addr2 = (x + 1) + stride * y;
            int ref_val1 = ref[y + idx1 + 1];
            int ref_val2 = ref[y + idx2 + 1];

            if (x < size) {
                src[addr1] = ref_val1;
            }
            if (x + 1 < size) {
                src[addr2] = ref_val2;
            }
        }
    }
}
}
