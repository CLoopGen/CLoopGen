#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern long ran_x[];
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 10; j++) {
        for (unsigned int k = 0; k < 10; k++) {
            aa[j * 10 + k] = ran_x[j * 10 + k];
        }
    }
}
