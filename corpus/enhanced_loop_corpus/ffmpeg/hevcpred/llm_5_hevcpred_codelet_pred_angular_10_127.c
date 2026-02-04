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
    uint16_t* src_base = &src[x];
    ptrdiff_t s = stride;
    for (y = 0; y < size; y++) {
        int ref_val = ref[y + idx + 1];
        if (fact) {
            ref_val = ((32 - fact) * ref_val + fact * ref[y + idx + 2] + 16) >> 5;
        }
        src_base[s * y] = ref_val;
    }
}
}
