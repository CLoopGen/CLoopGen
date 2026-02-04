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
    uint8_t prev_val = 0;
    for (x = last; x <= -1; x++) {
        int index = (x * inv_angle[mode - 11] + 128) >> 8;
        int adjusted_index = -1 + index;
        if (adjusted_index < 0) adjusted_index = 0;
        ref_tmp[x] = left[adjusted_index] + prev_val;
        prev_val = ref_tmp[x];
    }
}
