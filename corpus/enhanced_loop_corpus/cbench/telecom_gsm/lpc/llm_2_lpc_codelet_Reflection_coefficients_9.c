#include <stdio.h>

#include <inttypes.h>

typedef long longword;

typedef short word;

extern longword *L_ACF;
extern int i;
extern word temp;
extern word ACF[9];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element forward and backward)
    int stride = 2;
    for (i = 0; i <= 8; i += stride) {
        ACF[i] = ((L_ACF[i] << temp) >> 16);
    }
    // Handle odd indices in a second pass to cover all elements
    for (i = 1; i <= 8; i += stride) {
        ACF[i] = ((L_ACF[i] << temp) >> 16);
    }
}
