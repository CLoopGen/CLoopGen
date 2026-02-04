#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern long double chVals[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (int k = 0; k < 8; k++) {
            chVals[i * 8 + k] = 0;
        }
    }
}
