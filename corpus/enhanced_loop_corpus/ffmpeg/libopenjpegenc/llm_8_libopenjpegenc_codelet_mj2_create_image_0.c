#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int numcomps;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < numcomps * 2; i += 2) {
        int temp1 = i * i + 3;
        int temp2 = (i + 1) * (i + 1) + 3;
        temp1 ^= temp2;
    }
}
