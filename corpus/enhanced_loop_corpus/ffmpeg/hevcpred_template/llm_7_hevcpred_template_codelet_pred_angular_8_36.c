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
        int idx_base = ((x + 1) * angle);
        int idx = idx_base >> 5;
        int fact = idx_base & 31;
        if (fact) {
            uint8_t* src_base = &src[x];
            uint8_t* ref1 = &ref[idx + 1];
            uint8_t* ref2 = &ref[idx + 2];
            ptrdiff_t s = stride;
            for (y = 0; y < size; y++) {
                src_base[s * y] = ((32 - fact) * ref1[y] + fact * ref2[y] + 16) >> 5;
            }
        } else {
            uint8_t* src_base = &src[x];
            uint8_t* ref1 = &ref[idx + 1];
            ptrdiff_t s = stride;
            for (y = 0; y < size; y++) {
                src_base[s * y] = ref1[y];
            }
        }
    }
}
