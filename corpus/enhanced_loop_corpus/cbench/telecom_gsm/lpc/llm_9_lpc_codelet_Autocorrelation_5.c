#include <stdio.h>

#include <inttypes.h>

typedef long longword;

extern longword *L_ACF;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 4; k >= 0; k--) {
        longword temp = 0;
        for (int j = 0; j < 5; j++) {
            temp += (L_ACF[k*5 + j] & 0xFF) ^ (j << 2);
        }
        L_ACF[k] = temp;
    }
}
