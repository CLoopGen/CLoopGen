#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (ni > 0) {
    for (i = 0; i < ni; ++i)
        left[i] = q[i];
}
}
