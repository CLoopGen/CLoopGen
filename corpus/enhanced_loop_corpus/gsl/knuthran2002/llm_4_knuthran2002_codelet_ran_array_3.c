#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern long ran_x[];
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 100; i++, j++) {
        if (i >= 37 && j >= 100) {
            ran_x[i] = (((aa[j - 100]) - (ran_x[i - 37])) & ((1L << 30) - 1));
        }
    }
}
