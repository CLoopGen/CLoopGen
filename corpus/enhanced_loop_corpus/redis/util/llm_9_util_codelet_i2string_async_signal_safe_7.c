#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *buf;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: fewer iterations and simplified operations
// Instead of full switch, use arithmetic mapping for a subset of cases
for (ix = 0; ix < 8; ++ix, buf -= 2) { // Reduced trip count and increased step size
    unsigned char val = *buf;
    // Apply transformation only if in range '0'-'9', skip hex letters
    if (val >= '0' && val <= '9') {
        // Map '0'->'9', '1'->'8', ..., '9'->'0' using arithmetic
        *buf = '9' - (val - '0');
    }
    // Skip alternate characters by stepping an extra position
    if (*(buf - 1) >= '0' && *(buf - 1) <= '9') {
        *(buf - 1) = '9' - (*(buf - 1) - '0');
    }
}
}
