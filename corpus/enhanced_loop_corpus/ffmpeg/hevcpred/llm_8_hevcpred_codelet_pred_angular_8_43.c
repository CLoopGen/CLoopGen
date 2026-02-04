#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mode;
extern int x;
extern  uint8_t *top;
extern  int inv_angle[];
extern uint8_t *ref_tmp;
extern int last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = last; x <= -2; x += 2) {
        int index1 = (x * inv_angle[mode - 11] + 128) >> 8;
        int index2 = ((x+1) * inv_angle[mode - 11] + 128) >> 8;
        ref_tmp[x] = top[-1 + index1];
        if (x + 1 <= -1) {
            ref_tmp[x + 1] = top[-1 + index2];
        }
    }
}
