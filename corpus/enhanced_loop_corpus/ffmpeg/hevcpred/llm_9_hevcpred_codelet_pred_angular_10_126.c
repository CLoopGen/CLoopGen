#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mode;
extern int x;
extern  uint16_t *left;
extern  int inv_angle[];
extern uint16_t *ref_tmp;
extern int last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = last; x <= -1; x++) {
        int index = (x * inv_angle[mode - 11] + 128) >> 8;
        uint16_t val = left[-1 + index];
        ref_tmp[x] = val;
        if (x < -1) {
            index = ((x+1) * inv_angle[mode - 11] + 128) >> 8;
            val = left[-1 + index];
            ref_tmp[x+1] = val;
            x++;
        }
    }
}
