#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT g_decay_slope;
extern  INTFLOAT a[];
extern INTFLOAT ag[3];
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (simulating non-unit stride pattern)
    // Assuming array 'a' has at least 6 elements to safely allow strided access
    for (m = 0; m < 3; m++) {
        ag[m] = a[2 * m] * g_decay_slope;
    }
}
