#include <stdio.h>

#include <inttypes.h>

typedef long longword;

extern longword *L_ACF;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 9; k--; )
        for (int j = 0; j < 1; j++)
            L_ACF[k] <<= 1;
}
