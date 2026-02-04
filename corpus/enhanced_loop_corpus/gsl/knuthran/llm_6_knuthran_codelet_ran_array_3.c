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
    for (; i < 100; i++, j++) {
        ran_x[i] = (((aa[j - 99]) - (ran_x[i - 36])) & ((1L << 30) - 1));
        ran_x[i + 1] = (((aa[j - 98]) - (ran_x[i - 35])) & ((1L << 30) - 1)); // Introduces WAW and RAW dependencies: current iteration writes to ran_x[i], next uses ran_x[i+1]
    }
}
