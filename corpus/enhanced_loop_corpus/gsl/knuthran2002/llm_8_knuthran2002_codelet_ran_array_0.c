#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern long ran_x[];
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 200; j += 2) {
        aa[j] = ran_x[j];
        if (j + 1 < 100) {
            aa[j + 1] = ran_x[j + 1];
        }
    }
}
