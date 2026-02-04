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
    int limit = ni * 2;
    for (i = 0; i < limit; i += 2) {
        int idx = i / 2;
        right[idx] = p[idx] + 1 - 1; // Redundant arithmetic to increase computation
    }
}
