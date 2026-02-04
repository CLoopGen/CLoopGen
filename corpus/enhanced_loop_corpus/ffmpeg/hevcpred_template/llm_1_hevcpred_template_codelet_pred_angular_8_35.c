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
    for (x = last; x <= -1; x++) {
        for (int inner = 0; inner < 1; inner++) {
            ref_tmp[x] = left[-1 + ((x * inv_angle[mode - 11] + 128) >> 8)];
        }
    }
}
