#include <stdio.h>

#include <inttypes.h>

extern int patlen;
extern int skip[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    int upper_bound = 127 * 2 + 1;
    for (i = upper_bound; i >= 0; --i) {
        skip[i] = patlen;
    }
}
