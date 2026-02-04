#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    // Iterates from the end of the array to the beginning
    for (k = 159; k >= 0; k--)
        s[k] = (((((longword)(s[k]) * (longword)(16384 >> (3 - 1)) + 16384)) >> (15)));
}
