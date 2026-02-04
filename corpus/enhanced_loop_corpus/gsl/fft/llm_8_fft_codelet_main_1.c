#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double data[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i <= 20; i += 2) {
    ((data)[2 * (i)]) = ((data)[2 * (128 - i)]) = 1.;
    ((data)[2 * (i) + 1]) = ((data)[2 * (128 - i) - 1]) = 2.;
}
}
