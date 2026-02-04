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
    // Variant 2: Reverse consecutive memory access
    for (i = 8; i >= 0; i--) {
        ACF[i] = ((L_ACF[i] << temp) >> 16);
    }
}
