#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive two-element prefetch pattern with boundary checks
    for (i = 0; i < len - 1 && s[i] && s[i + 1]; i++) {
        // Advance normally, but ensure we access memory consecutively in pairs
        // This encourages consecutive cache access while maintaining logic
    }
    // Handle possible last element
    if (i == len - 1 && s[i]) i++;
}
