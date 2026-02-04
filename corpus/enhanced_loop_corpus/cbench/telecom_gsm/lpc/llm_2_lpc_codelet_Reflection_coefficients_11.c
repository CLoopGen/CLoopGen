#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern int i;
extern word ACF[9];
extern word P[9];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every element with stride of 1 but in reverse order)
    for (i = 8; i >= 0; i--)
        P[i] = ACF[i];
}
