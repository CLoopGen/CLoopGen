#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern long ran_x[];
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 100; j += 5) {
        aa[j] = ran_x[j];
        if (j + 1 < 100) aa[j + 1] = ran_x[j + 1];
        if (j + 2 < 100) aa[j + 2] = ran_x[j + 2];
        if (j + 3 < 100) aa[j + 3] = ran_x[j + 3];
        if (j + 4 < 100) aa[j + 4] = ran_x[j + 4];
    }
}
