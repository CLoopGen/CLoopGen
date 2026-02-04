#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mode;
extern int x;
extern  uint8_t *left;
extern  int inv_angle[];
extern uint8_t *ref_tmp;
extern int last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal order
    int stride = (inv_angle[mode - 11] + 64) >> 7; // Larger stride for sparser access
    int i = 0;
    for (x = last; x <= -1; x++, i++)
        ref_tmp[x] = left[-1 + ((i * stride * inv_angle[mode - 11] + 128) >> 8)];
}
