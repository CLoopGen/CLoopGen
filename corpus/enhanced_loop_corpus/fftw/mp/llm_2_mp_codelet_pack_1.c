#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *d;
extern int e;
extern int l;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (backwards)
    for (i = l - 1; i >= 0; i -= 2, --e) {
        if (i < l && d[i] != 0)
            break;
        // Decrement e an extra time to match original semantics per iteration
        if (i > 0) --e;
    }
}
