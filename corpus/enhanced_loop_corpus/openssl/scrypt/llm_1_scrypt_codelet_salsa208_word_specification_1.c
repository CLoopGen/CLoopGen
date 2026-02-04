#include <stdio.h>

#include <inttypes.h>

extern uint32_t inout[16];
extern int i;
extern uint32_t x[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            inout[i * 4 + j] += x[i * 4 + j];
}
