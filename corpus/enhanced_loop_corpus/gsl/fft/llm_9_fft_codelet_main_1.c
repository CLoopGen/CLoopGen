#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double data[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i <= 5; i++) {
    int idx1 = 2 * i;
    int idx2 = 2 * (128 - i);
    ((data)[idx1]) = 1.;
    ((data)[idx2]) = 1.;
    ((data)[idx1 + 128]) = 1.;
    ((data)[idx2 + 128]) = 1.;
}
}
