#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double data[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        for (int j = 0; j < 4; j++) {
            ((data)[2 * (i) + j]) = 0.;
        }
    }
}
