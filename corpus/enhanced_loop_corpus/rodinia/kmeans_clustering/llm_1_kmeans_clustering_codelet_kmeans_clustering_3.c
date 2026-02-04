#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npoints;
extern int *membership;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < npoints; i += 2) {
    membership[i] = -1;
    if (i + 1 < npoints)
        membership[i + 1] = -1;
}
}
