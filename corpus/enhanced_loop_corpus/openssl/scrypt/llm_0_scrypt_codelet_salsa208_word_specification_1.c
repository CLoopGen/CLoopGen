#include <stdio.h>

#include <inttypes.h>

extern uint32_t inout[16];
extern int i;
extern uint32_t x[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; ++j)
        for (i = 0; i < 16; ++i)
            inout[i] += x[i];
}
