#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern long ran_x[];
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 50; j++) {
        aa[2*j] = ran_x[2*j] + 1;
        aa[2*j + 1] = ran_x[2*j + 1] - 1;
    }
}
