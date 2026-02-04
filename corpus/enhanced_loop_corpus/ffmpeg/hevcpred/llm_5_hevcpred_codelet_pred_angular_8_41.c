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
    uint8_t* src_base = &src[x];
    uint8_t* ref_base1 = &ref[idx + 1];
    uint8_t* ref_base2 = &ref[idx + 2];
    ptrdiff_t s = stride;
    
    if (fact == 0) {
        for (y = 0; y < size; y++) {
            src_base[s * y] = ref_base1[y];
        }
    } else {
        int inv_fact = 32 - fact;
        for (y = 0; y < size; y++) {
            src_base[s * y] = (inv_fact * ref_base1[y] + fact * ref_base2[y] + 16) >> 5;
        }
    }
}
}
