#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (process array from last to first element)
    for (k = 159; k >= 0; k--)
        s[k] = (((((longword)(s[k]) * (longword)(16384 >> (2 - 1)) + 16384)) >> (15)));
}
