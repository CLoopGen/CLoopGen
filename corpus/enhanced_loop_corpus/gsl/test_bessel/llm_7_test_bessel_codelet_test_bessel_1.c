#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double J[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    J[0] = 0;
    for (i = 1; i < 100; i++) {
        J[i] = J[i-1] + 1.0;
    }
}
