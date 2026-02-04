#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int maxsf[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer = 1;
for (i = 0; i < sizeof (maxsf) / sizeof (maxsf[0]); ++i) {
    int inner;
    for (inner = 0; inner < outer; ++inner)
        maxsf[i] = 255;
}
}
