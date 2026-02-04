#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

extern int32 n_el;
extern int32 i;
extern uint32 *buf32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 prev_val = 0;
    for (i = 0; i < n_el; i++) {
        int32 curr = *(buf32 + i);
        *(buf32 + i) = ((255 & curr >> 24) | (65280 & curr >> 8) | (16711680 & curr << 8) | (4278190080U & curr << 24)) ^ prev_val;
        prev_val = curr;
    }
}
