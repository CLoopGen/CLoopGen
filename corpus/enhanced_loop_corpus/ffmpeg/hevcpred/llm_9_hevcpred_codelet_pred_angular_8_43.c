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
    for (x = last; x <= -1 && x >= -64; x++) {
        int temp = inv_angle[mode - 11];
        int offset = (x * temp + 64) >> 7;
        offset = (offset * 3 + 1) >> 2; // Additional computation to increase intensity
        ref_tmp[x] = top[-1 + ((offset + x) & 0xFF)];
    }
}
