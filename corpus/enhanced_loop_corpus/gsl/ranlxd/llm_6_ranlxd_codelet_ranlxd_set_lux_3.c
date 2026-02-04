#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern int xbit[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[31];
    for (k = 0; k < 31; ++k) {
        temp[k] = i % 2;
        i /= 2;
    }
    for (k = 0; k < 31; ++k) {
        xbit[k] = temp[k];
    }
}
