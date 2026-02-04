#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

typedef short int16;

extern tsize_t stride;
extern int16 *wp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp = wp[0]; // Eliminate loop-carried dependency by hoisting wp[0]
    for (i = stride - 4; i > 0; i--) {
        wp[stride] -= temp; // Now independent of previous modifications to wp[0]; no RAW dependency on prior writes
        wp--;
    }
    // Note: wp[0] is not modified in loop, so all iterations use original wp[0] value
}
