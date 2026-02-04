#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

extern INT n;
extern INT npad;
extern INT k;
extern R *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (k = n - 1; k < npad; k += 2)
        buf[k] = 0;
    // Handle potential odd-sized range if needed, but original logic implies filling only up to npad
    if ((n - 1) % 2 == 0 && (npad - 1) >= (n - 1)) {
        buf[npad - 1] = 0;
    }
}
