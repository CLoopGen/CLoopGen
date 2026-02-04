#include <stdio.h>

#include <inttypes.h>

extern uint32_t inout[16];
extern int i;
extern uint32_t x[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        uint32_t temp1 = x[i];
        uint32_t temp2 = x[i + 8];
        inout[i] += temp1;
        inout[i + 8] += temp2;
        inout[i] += temp2;
        inout[i + 8] += temp1;
    }
}
