#include <stdio.h>

#include <inttypes.h>

extern  uint64_t *a;
extern uint64_t aa[4];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, processing alternating elements
    for (i = 0; i < 4; i += 2) {
        aa[i]     = a[i] + a[i + 4];
        if (i + 1 < 4)
            aa[i + 1] = a[i + 1] + a[i + 5];
    }
}
