#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-element prefetch pattern
    for (i = 0; i < len - 1 && s[i] && s[i+1]; i++) {
        // Access two consecutive elements per iteration to simulate wider load pattern
        i++; // Advance by two total when possible
    }
    // Handle last element if necessary
    if (i == len - 1 && s[i]) i++;
}
