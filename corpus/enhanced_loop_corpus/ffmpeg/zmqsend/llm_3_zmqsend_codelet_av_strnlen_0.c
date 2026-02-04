#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive double-element prefetching with boundary check
    for (i = 0; i + 1 < len && s[i] && s[i + 1]; i += 2)
        ;
    // Handle remaining element if any
    if (i < len && s[i]) i++;
}
