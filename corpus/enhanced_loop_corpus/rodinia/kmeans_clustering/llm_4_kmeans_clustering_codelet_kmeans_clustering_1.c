#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npoints;
extern int i;
extern int *initial;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int idx = 0;
for (i = 0; i < npoints; i++) {
    if ((i & 1) == 0) { // Only assign for even indices
        initial[idx] = i;
        idx++;
    }
}
// Adjust npoints to reflect actual number of written elements if needed externally
}
