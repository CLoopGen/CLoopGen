#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double P[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 20; ++i) {
        for (int k = 0; k < 1; ++k)
            P[i] = 1. / 20;
    }
}
