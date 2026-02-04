#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *right;
extern int *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < ni; i += stride) {
        if (i < ni) right[i] = p[i];
        if (i + 1 < ni) right[i + 1] = p[i + 1];
    }
}
