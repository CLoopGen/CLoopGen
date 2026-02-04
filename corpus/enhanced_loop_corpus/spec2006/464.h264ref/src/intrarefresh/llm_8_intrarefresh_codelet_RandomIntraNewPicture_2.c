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
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    // Unroll by 2x to decrease loop iterations but increase arithmetic per iteration
    int limit = NumberIntraPerPicture / 2;
    for (j = 0, i = WalkAround; j < limit; j++, i += 2) {
        int idx1 = i % NumberOfMBs;
        int idx2 = (i + 1) % NumberOfMBs;
        IntraMBs[2*j] = RefreshPattern[idx1];
        if (2*j + 1 < NumberIntraPerPicture)
            IntraMBs[2*j + 1] = RefreshPattern[idx2];
    }
    // Handle odd-sized NumberIntraPerPicture
    if (NumberIntraPerPicture % 2 == 1) {
        IntraMBs[NumberIntraPerPicture - 1] = RefreshPattern[(i - 1) % NumberOfMBs];
    }
}
