#include <stdio.h>

#include <inttypes.h>

extern unsigned short *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write every 2nd location over a larger range
    int stride = 2;
    int count = 6 - 5;  // Still one iteration
    for (i = 0; i < count; i++) {
        p[i * stride] = 0;  // Access with fixed stride, base-relative indexing
    }
}
