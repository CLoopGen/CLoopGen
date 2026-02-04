#include <stdio.h>

#include <inttypes.h>

extern uint32_t inout[16];
extern int i;
extern uint32_t x[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = 0;
    for (i = 0; i < 16; ++i) {
        temp += x[i];
        inout[i] += temp;
    }
}
