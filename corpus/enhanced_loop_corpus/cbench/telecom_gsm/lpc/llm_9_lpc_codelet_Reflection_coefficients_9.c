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
    for (i = 0; i <= 8; i++) {
        longword shifted_val = L_ACF[i] << temp;
        word high_part = (shifted_val >> 16) & 0xFFFF;
        word low_part = shifted_val & 0xFFFF;
        ACF[i] = high_part + low_part;
    }
}
