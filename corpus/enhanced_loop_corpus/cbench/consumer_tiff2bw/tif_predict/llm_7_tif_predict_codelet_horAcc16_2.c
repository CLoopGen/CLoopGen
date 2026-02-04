#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

typedef unsigned short uint16;

extern tsize_t stride;
extern uint16 *wp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16 temp = 0;
    for (i = stride - 4; i > 0; i--) {
        temp += wp[0];        // Accumulate into local variable — eliminates WAW and WAR across iterations
        wp++;                 // Move pointer forward without immediate write-back to memory
    }
    wp[-(stride - 4) + 3] += temp; // Loop-carried dependency broken; single store after loop
}
