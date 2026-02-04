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
    for (x = last; x <= -3; x++) {
        ref_tmp[x]   = left[-1 + ((x * inv_angle[mode - 11] + 128) >> 8)];
        ref_tmp[x+1] = left[-1 + (((x+1) * inv_angle[mode - 11] + 128) >> 8)];
        ref_tmp[x+2] = left[-1 + (((x+2) * inv_angle[mode - 11] + 128) >> 8)];
    }
    // Handle remaining iterations if any (x == -2 or x == -1)
    while (x <= -1) {
        ref_tmp[x] = left[-1 + ((x * inv_angle[mode - 11] + 128) >> 8)];
        x++;
    }
}
