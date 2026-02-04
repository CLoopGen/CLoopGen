#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in forward order, then second pass for odd indices)
    for (k = 0; k <= 159; k += 2)
        s[k] = (((((longword)(s[k]) * (longword)(16384 >> (2 - 1)) + 16384)) >> (15)));
    for (k = 1; k <= 159; k += 2)
        s[k] = (((((longword)(s[k]) * (longword)(16384 >> (2 - 1)) + 16384)) >> (15)));
}
