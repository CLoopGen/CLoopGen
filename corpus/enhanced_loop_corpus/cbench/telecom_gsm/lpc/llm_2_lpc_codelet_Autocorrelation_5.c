#include <stdio.h>

#include <inttypes.h>

typedef long longword;

extern longword *L_ACF;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (k = 8; k >= 0; k -= 2) {
        L_ACF[k] = 0;
        if (k > 0) L_ACF[k-1] = 0;
    }
}
