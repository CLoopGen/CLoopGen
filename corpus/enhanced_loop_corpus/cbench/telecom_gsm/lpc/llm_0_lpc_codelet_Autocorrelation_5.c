#include <stdio.h>

#include <inttypes.h>

typedef long longword;

extern longword *L_ACF;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth = 0; depth < 2; ++depth)
        for (k = 9; k--; L_ACF[k] = 0)
            ;
}
