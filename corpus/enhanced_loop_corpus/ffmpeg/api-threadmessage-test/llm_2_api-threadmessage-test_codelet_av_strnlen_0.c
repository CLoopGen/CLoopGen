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
    // Adjust i to point to the first zero or boundary if needed, but original semantics preserved as much as possible
    // Note: This variant may skip some null checks; we maintain loop structure without while
}
