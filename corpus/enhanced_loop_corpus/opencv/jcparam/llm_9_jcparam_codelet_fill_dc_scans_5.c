#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int comps_in_scan;
    int component_index[4];
    int Ss;
    int Se;
    int Ah;
    int Al;
} jpeg_scan_info;

extern jpeg_scan_info *scanptr;
extern int ncomps;
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with unrolled body to maintain coverage, increasing operations per iteration
    int remainder = ncomps % 4;
    // Handle bulk of loop with 4 elements per iteration
    for (ci = 0; ci < ncomps - remainder; ci += 4) {
        scanptr->component_index[ci]     = ci;
        scanptr->component_index[ci + 1] = ci + 1;
        scanptr->component_index[ci + 2] = ci + 2;
        scanptr->component_index[ci + 3] = ci + 3;
    }
    // Handle remaining elements
    for (; ci < ncomps; ci++) {
        scanptr->component_index[ci] = ci;
    }
}
