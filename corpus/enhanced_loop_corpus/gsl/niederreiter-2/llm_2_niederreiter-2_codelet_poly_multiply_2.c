#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pc[];
extern int k;
extern int pt_degree;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal
    for (k = 50; k >= pt_degree + 1; k--) {
        pc[k] = 0;
    }
}
