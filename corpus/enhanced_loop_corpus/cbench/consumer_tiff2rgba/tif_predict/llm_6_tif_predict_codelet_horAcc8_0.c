#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tsize_t temp = 0;
    for (i = stride - 4; i > 0; i--) {
        temp += cp[i];         // Accumulate into local temp (removes WAW on cp[stride])
        cp[stride] = temp;     // Write once, reducing WAW hazards
    }
    *cp += temp;               // Final update to original memory location
}
