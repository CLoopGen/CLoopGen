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
    // Variant 1: Eliminate WAW and RAW dependencies by using temporary accumulation
    // Introduces local variable to break loop-carried dependency on wp[stride]
    int32 temp = 0;
    for (i = stride - 4; i > 0; i--) {
        temp += wp[0];
        wp++;
    }
    wp[stride] += temp;  // Update only once after loop
}
