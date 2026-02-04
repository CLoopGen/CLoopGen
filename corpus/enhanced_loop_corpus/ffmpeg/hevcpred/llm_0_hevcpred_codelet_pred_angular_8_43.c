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
    for (int temp_x = last; temp_x <= -1; temp_x++) {
        for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
            x = temp_x;
            ref_tmp[x] = top[-1 + ((x * inv_angle[mode - 11] + 128) >> 8)];
        }
    }
}
