#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long aa[];
extern unsigned long ran_x[];
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 37; i++, j++) {
        unsigned long temp1 = aa[j - 100];
        unsigned long temp2 = aa[j - 37];
        ran_x[i] = ((temp1 - temp2) & ((1UL << 30) - 1));
    }
}
