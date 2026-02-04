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
    uint8_t *src_base = &src[x];
    uint8_t *ref_base = &ref[idx + 1];
    if (fact) {
        for (y = 0; y < size; y++) {
            src_base[stride * y] = ((32 - fact) * ref_base[y] + fact * ref_base[y + 1] + 16) >> 5;
        }
    } else {
        for (y = 0; y < size; y++)
            src_base[stride * y] = ref_base[y];
    }
}
}
