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
    for (i = 0; i < ni; i += 2) {
        if (i < ni) left[i] = q[i];
        if (i + 1 < ni) left[i + 1] = q[i + 1];
    }
}
