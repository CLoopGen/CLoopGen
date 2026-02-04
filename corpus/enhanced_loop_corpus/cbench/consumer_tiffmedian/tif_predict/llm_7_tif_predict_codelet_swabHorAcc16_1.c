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
    // Variant 2: Introduce stronger loop-carried RAW and WAW dependencies
    // Each iteration depends on the previous write to wp[stride]
    for (i = stride - 4; i > 0; i--) {
        wp[stride] = wp[stride] + wp[0] + 1; // Read-modify-write creates loop-carried dependency
        wp++;
    }
}
