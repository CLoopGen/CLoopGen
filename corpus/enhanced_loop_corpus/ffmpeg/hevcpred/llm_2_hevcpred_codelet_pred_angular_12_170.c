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
    uint16_t *src_base = &src[x];
    uint16_t *ref_base1 = &ref[idx + 1];
    uint16_t *ref_base2 = &ref[idx + 2];
    if (fact) {
        for (y = 0; y < size; y++) {
            src_base[y * stride] = ((32 - fact) * ref_base1[y] + fact * ref_base2[y] + 16) >> 5;
        }
    } else {
        for (y = 0; y < size; y++)
            src_base[y * stride] = ref_base1[y];
    }
}
}
