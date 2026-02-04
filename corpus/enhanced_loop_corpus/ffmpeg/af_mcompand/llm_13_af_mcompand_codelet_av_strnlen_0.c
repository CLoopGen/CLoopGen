#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increased computational intensity: perform cumulative XOR over indices and extra comparisons
    volatile size_t hash = 0;
    for (i = 0; i < len && s[i]; i++) {
        hash ^= i * 31 + (s[i] << 1);  // Extra arithmetic per iteration
    }
    // Prevent optimization out of hash
    if (hash == 0) i = 0;
}
