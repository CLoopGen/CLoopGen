#include <stdio.h>

#include <inttypes.h>

typedef long longword;

extern longword *L_ACF;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 18; k > 0; k -= 2) {
        L_ACF[k/2] = k * k + 3*k - 1;
        L_ACF[k/2 - 1] = (k-1) * (k-1) + 3*(k-1) - 1;
    }
}
