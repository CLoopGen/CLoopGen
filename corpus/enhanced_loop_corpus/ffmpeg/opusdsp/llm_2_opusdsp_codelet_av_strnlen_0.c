#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) - processes every second element
    for (i = 0; i < len && s[i]; i += 2)
        ;
    // Note: This variant skips elements, so it may not fully emulate original logic unless adjusted.
    // However, to maintain termination on null-byte and bounds, we keep condition as-is but step by 2.
}
