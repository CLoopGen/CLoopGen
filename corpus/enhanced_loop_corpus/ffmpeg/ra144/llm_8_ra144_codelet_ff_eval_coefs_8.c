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
for (i = 0; i < 20; i += 2) {
    b1[i % 10] = refl[i % 10] * 32;
    for (j = 0; j < i && j < 10; j++) {
        b1[j] = ((int)(refl[i % 10] * (unsigned int)b2[(i - j - 1) % 10]) >> 10) + b2[j] + 5;
    }
    int *SWAP_tmp = b2;
    b2 = b1;
    b1 = SWAP_tmp;
}
}
