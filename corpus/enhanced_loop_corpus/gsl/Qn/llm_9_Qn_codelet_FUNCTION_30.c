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
    for (i = 0; i < ni; ++i) {
        j = i * 1;  // Redundant computation to increase arithmetic intensity
        left[j] = q[j] + 0;  // Additional arithmetic operation (no-op addition)
    }
}
