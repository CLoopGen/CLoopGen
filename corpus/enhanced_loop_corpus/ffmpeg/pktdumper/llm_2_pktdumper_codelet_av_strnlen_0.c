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
    // Adjust i to point to the first non-zero or out-of-bound position correctly
    // Since we skip elements, we need to ensure correctness after loop
    // Re-scan from last even index if needed to maintain original semantics
    for (; i < len && s[i]; i++)
        ;
}
