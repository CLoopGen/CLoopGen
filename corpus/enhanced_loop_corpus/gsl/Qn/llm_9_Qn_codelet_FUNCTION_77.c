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
    int stride = 1;
    for (i = 0; i < ni; ++i) {
        right[i * stride] = p[i * stride] + 1 - 1; // Redundant arithmetic to increase computational intensity
    }
}
