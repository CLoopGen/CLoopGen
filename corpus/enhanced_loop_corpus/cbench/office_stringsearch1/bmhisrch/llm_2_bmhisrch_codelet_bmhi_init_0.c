#include <stdio.h>

#include <inttypes.h>

extern int patlen;
extern int skip[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2
    for (i = 0; i <= (127 * 2 + 1); i += 2)
        skip[i] = patlen;
    // Handle odd indices if necessary, but original loop sets all entries
    // So we add a second pass with offset stride to maintain correctness
    for (i = 1; i <= (127 * 2 + 1); i += 2)
        skip[i] = patlen;
}
