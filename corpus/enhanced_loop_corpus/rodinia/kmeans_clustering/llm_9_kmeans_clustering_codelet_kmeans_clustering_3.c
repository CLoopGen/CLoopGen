#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npoints;
extern int *membership;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = npoints - 1; i >= 0; i--) {
    membership[i] = -1;
    membership[i] = membership[i] * 1; // Redundant arithmetic to increase computational intensity
}
}
