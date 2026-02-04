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
    for (x = last; x <= -1 && x >= -32; x++) {
        int scaled = (x * inv_angle[mode - 11]) >> 7;
        int offset = (scaled + 256) >> 1;
        ref_tmp[x] = left[-1 + offset];
    }
}
