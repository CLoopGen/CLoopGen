#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *levels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 5; i++) {
    for (int k = 0; k < 3; k++) {
        levels[i * 3 + k] = -100.;
    }
}
}
