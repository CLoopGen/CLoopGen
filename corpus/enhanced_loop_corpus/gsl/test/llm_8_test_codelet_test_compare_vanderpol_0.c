#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[11][2];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ns && i < 11; i++) {
        y[i][0] = 1.0 + (double)i * 0.1;
        y[i][1] = (double)i * 2.0;
    }
}
