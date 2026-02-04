#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern long ran_x[];
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 100; j++)
        aa[j] = ran_x[j];
    // Introduce a loop-carried dependency: each iteration depends on the previous one via a cumulative effect
    // Although the original store is preserved, we add a dummy dependency chain
    long temp = 0;
    for (j = 0; j < 100; j++) {
        temp += aa[j];      // RAW dependence: use of aa[j] after write
        aa[j] = temp;       // WAW dependence: overwrite aa[j], creating write-after-write
    }
}
