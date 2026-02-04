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
    for (i = 0; i < ni * 2; ++i) {
        int idx = i / 2;
        if (idx < ni) {
            right[idx] = p[idx] + 1 - 1; // Redundant arithmetic to increase computational intensity
        }
    }
}
