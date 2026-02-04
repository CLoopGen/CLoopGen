#include <stdio.h>

#include <inttypes.h>

extern int coeff[64];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = pos; i < 64; i++)
        coeff[i] = 0;
    pos = 64; // WAW dependency introduced: write-after-write on 'pos'
}
