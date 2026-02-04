#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double data[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        data[2 * i] = 0.;
        data[2 * i + 1] = data[2 * i]; // Introduced RAW dependency: use of data[2*i] just after write
    }
}
