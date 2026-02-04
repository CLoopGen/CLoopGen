#include <stdio.h>

#include <inttypes.h>

extern int *RefreshPattern;
extern int *IntraMBs;
extern int WalkAround;
extern int NumberOfMBs;
extern int NumberIntraPerPicture;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Prefetching Pattern
    // Instead of strided access via i % NumberOfMBs, we make a direct consecutive copy
    // by precomputing a temporary buffer or reorganizing access to be linear.
    // Here we assume RefreshPattern has been pre-rotated or mapped so that starting at WalkAround,
    // the next NumberIntraPerPicture elements can be accessed consecutively.
    int start_index = WalkAround % NumberOfMBs;
    for (j = 0; j < NumberIntraPerPicture; j++) {
        IntraMBs[j] = RefreshPattern[(start_index + j) % NumberOfMBs];
    }
}
