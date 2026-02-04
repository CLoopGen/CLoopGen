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
    int j;
    for (i = 0; i < ni * 2; ++i) {
        j = i / 2;
        if (i % 2 == 0 && j < ni)
            left[j] = q[j] + 1 - 1; // Redundant arithmetic to increase intensity
    }
}
