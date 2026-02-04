#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double J[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 4th element in each iteration, forward traversal)
    for (i = 0; i < 100; i += 4) {
        J[i] = i * 20;
        if (i + 1 < 100) J[i + 1] = (i + 1) * 20;
        if (i + 2 < 100) J[i + 2] = (i + 2) * 20;
        if (i + 3 < 100) J[i + 3] = (i + 3) * 20;
    }
}
