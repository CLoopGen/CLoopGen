#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double data[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 10; i++) {
    int idx1 = 2 * (i + 1);
    int idx2 = 2 * (128 - (i + 1));
    ((data)[idx1]) = 1.;
    ((data)[idx2]) = 1.;
}
}
