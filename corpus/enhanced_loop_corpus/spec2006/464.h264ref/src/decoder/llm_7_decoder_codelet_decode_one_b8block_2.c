#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern int mv[2][4][4];
extern int bx0;
extern int bx1;
extern int by0;
extern int by1;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Eliminate all loop-carried dependencies by removing overlapping writes and introducing independent indexing
    // Use temporary local storage to remove immediate data dependencies, then write back
    int temp0[4][4];
    int temp1[4][4];

    for (by = by0; by < by1; by++) {
        for (bx = bx0; bx < bx1; bx++) {
            // Perform computation in local temporaries to break WAR/WAW hazards
            temp0[by][bx] = 0;
            temp1[by][bx] = 0;
        }
    }

    // Now write back to shared mv array — no intra-loop dependencies
    for (by = by0; by < by1; by++) {
        for (bx = bx0; bx < bx1; bx++) {
            mv[0][by][bx] = temp0[by][bx];
            mv[1][by][bx] = temp1[by][bx];
        }
    }
}
