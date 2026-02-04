#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (k = 0; k <= 159; k += 2) {
        s[k] = (((((longword)(s[k]) * (longword)(16384 >> (4 - 1)) + 16384)) >> (15)));
    }
    // Handle odd indices in a second pass to maintain full coverage
    for (k = 1; k <= 159; k += 2) {
        s[k] = (((((longword)(s[k]) * (longword)(16384 >> (4 - 1)) + 16384)) >> (15)));
    }
}
