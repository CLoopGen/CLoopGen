#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; ++i) {
        if (i % 2 == 0)
            t[i] = 0.;
        else
            continue;
    }
}
