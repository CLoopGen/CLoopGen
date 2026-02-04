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
    int temp_val;
    for (x = last; x <= -1; x++) {
        temp_val = (x * inv_angle[mode - 11] + 128) >> 8;
        ref_tmp[x] = top[-1 + temp_val];
    }
}
