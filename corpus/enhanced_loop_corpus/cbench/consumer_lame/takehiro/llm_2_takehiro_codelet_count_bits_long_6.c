#include <stdio.h>

#include <inttypes.h>

extern int ix[576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (access every 4th element in reverse)
    for (; i > 3; i -= 4) {
        if (ix[i - 1] | ix[i - 3])
            break;
    }
}
