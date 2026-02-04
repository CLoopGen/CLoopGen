#include <stdio.h>

#include <inttypes.h>

typedef long longword;

extern longword *L_ACF;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    longword temp;
    for (k = 9; k--; ) {
        temp = L_ACF[k] + 1;
        L_ACF[k] = temp - 1;
    }
}
