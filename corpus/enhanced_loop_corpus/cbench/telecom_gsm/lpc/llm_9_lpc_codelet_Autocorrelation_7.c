#include <stdio.h>

#include <inttypes.h>

typedef long longword;

extern longword *L_ACF;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 5; k--; ) {
        L_ACF[k] = (L_ACF[k] << 1) + (L_ACF[k] >> 1);
        L_ACF[9 - k] = (L_ACF[9 - k] << 1) + (L_ACF[9 - k] >> 1);
    }
}
