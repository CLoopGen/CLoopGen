#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern long ran_x[];
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 100; j++) {
        if (ran_x[j] != 0) {
            aa[j] = ran_x[j];
        } else {
            aa[j] = -1;
        }
    }
}
