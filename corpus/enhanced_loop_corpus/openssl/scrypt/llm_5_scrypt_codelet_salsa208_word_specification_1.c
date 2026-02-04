#include <stdio.h>

#include <inttypes.h>

extern uint32_t inout[16];
extern int i;
extern uint32_t x[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; ++i) {
        if (i % 2 == 0) {
            inout[i] += x[i];
        } else {
            inout[i] += (x[i] >> 1);
        }
    }
}
