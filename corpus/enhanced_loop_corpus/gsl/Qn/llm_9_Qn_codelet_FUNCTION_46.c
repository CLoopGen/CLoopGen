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
    int stride = 4;
    for (i = 0; i < ni; i += stride) {
        left[i] = q[i];
        if (i + 1 < ni) left[i + 1] = q[i + 1];
        if (i + 2 < ni) left[i + 2] = q[i + 2];
        if (i + 3 < ni) left[i + 3] = q[i + 3];
    }
}
