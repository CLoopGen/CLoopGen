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
    // Re-scan from the last even index to ensure we don't skip the null terminator
    for (; i < len && s[i]; i++)
        ;
}
