#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double data[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 256; i++) {
    ((data)[i]) = 0.;
}
}
