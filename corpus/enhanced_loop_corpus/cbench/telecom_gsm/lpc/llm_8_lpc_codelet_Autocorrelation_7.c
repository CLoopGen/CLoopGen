#include <stdio.h>

#include <inttypes.h>

typedef long longword;

extern longword *L_ACF;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 18; k--; ) {
        L_ACF[k % 10] <<= 2;
        L_ACF[(k + 3) % 10] += 1;
    }
}
