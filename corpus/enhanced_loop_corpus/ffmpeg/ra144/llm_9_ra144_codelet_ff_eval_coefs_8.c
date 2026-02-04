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
for (i = 0; i < 5; i++) {
    b1[i] = refl[i] * 8;
    for (j = 0; j < i; j += 2) {
        b1[j] = ((int)(refl[i] * (unsigned int)b2[i - j - 1]) >> 14) + b2[j];
        if (j + 1 < i) {
            b1[j + 1] = ((int)(refl[i] * (unsigned int)b2[i - j - 2]) >> 14) + b2[j + 1];
        }
    }
    for (j = 0; j < 10; j++) {
        b1[j] += 1;
    }
    int *SWAP_tmp = b2;
    b2 = b1;
    b1 = SWAP_tmp;
}
}
