#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive write using array indexing instead of pointer arithmetic
    word *base = r;
    for (i = 0; i < 8; i++)
        base[i] = 0;
    r += 8;
}
