#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration order
    for (i = (i1 >> 1) - 1; i >= (i0 >> 1); i--) {
        ptrdiff_t idx = 2 * i;
        p[idx + 1] += (int)(p[idx - 0] + p[idx + 2]) >> 1;
    }
}
