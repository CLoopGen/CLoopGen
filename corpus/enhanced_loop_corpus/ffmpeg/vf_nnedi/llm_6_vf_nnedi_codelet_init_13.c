#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int k;
extern int *offt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; j++)
    for (k = 0; k < 64; k++) {
        int temp = (k >> 3) << 5;
        temp += ((j & 3) << 3);
        temp += (k & 7);
        offt[j * 64 + k] = temp;
    }
}
