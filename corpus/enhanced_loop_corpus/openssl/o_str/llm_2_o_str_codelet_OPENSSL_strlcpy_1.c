#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern  char *src;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2
    for (; size > 1 && src[0]; size--, l++) {
        *dst++ = src[0];
        src += 2;  // Advance source by 2 positions each iteration
    }
}
