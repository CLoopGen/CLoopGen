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
        for (j = 0; j < i; j++) {
            b1[j] = ((int)(refl[i] * (unsigned int)b2[i - j - 1]) >> 12) + b2[j];
        }
        int temp_val = b1[0]; 
        b1[0] = b2[0]; 
        b2[0] = temp_val; 
        for (int k = 1; k < 10; k++) {
            b1[k] ^= b2[k]; 
        }
    }
}
