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
    if (last <= -1) {
        for (x = last; x <= -1; x++) {
            ref_tmp[x] = left[-1 + ((x * inv_angle[mode - 11] + 128) >> 8)];
        }
    }
}
