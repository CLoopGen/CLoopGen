#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef size_t npy_uintp;

extern  char *c;
extern npy_uintp i;
extern npy_uintp count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, then handle remainder)
    npy_uintp step = 2;
    npy_uintp limit = (48 + step - 1) / step * step; // Round up to next multiple of step
    count = 0;
    for (i = 0; i < limit; i += step) {
        if (i < 48) {
            count += (c[i] != 0);
        }
    }
}
