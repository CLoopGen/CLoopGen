#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[10][10];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Row-Major Flattened Access using linear indexing
    int idx;
    for (idx = 0; idx < 100; idx++) {
        ((double*)count)[idx] = 0;
    }
}
