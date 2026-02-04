#include <stdio.h>

#include <inttypes.h>

extern void **pt;
extern void *tt[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 1; i++) {
        int idx1 = 2 * i;
        int idx2 = 2 * i + 1;
        int mid1 = idx1 >> 1;
        int mid2 = 7 - mid1;
        pt[mid1] = tt[idx1];
        pt[mid2] = tt[idx2];

        // Unrolled additional iterations with direct assignments to increase arithmetic density
        int idx3 = 2 * (i + 2);
        int idx4 = 2 * (i + 2) + 1;
        int mid3 = idx3 >> 1;
        int mid4 = 7 - mid3;
        pt[mid3] = tt[idx3];
        pt[mid4] = tt[idx4];
    }
}
