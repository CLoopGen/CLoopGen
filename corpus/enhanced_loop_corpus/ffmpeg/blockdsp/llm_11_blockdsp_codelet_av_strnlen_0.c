#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through array in larger increments
    // and compensate with internal unrolling to maintain memory access coverage
    for (i = 0; i < len - 3; i += 4) {
        if (!s[i]) break;
        if (!s[i+1]) { i += 1; break; }
        if (!s[i+2]) { i += 2; break; }
        if (!s[i+3]) { i += 3; break; }
    }
    // Handle remaining elements if loop didn't terminate early
    while (i < len && s[i]) i++; // Note: This while is for cleanup only, not replacing the main loop
}
