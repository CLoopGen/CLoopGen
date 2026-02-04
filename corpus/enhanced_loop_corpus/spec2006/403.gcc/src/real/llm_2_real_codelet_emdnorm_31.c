#include <stdio.h>

#include <inttypes.h>

extern unsigned short s[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element)
    for (i = 2; i < (6 + 3) - 1; i += 2)
        s[i] = 0;
}
