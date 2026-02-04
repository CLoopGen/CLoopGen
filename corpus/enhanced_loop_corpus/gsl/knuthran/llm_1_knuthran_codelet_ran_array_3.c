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
    for (unsigned int k = 0; k < 100; k++) {
        for (; i < 100 && i == k; i++, j++) {
            ran_x[i] = (((aa[j - 100]) - (ran_x[i - 37])) & ((1L << 30) - 1));
        }
    }
}
