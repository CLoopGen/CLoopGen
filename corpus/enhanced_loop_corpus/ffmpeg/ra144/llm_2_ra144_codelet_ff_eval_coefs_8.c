#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *refl;
extern int *b1;
extern int *b2;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 10; i++) {
    b1[i] = refl[i] * 16;
    for (j = 0; j < i; j++)
        b1[j] = ((int)(refl[i] * (unsigned int)b2[i - j - 1]) >> 12) + b2[j];
    int *SWAP_tmp = b1;
    b1 = b2;
    b2 = SWAP_tmp;
}
}
