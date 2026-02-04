#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sr;
extern real *si;
extern integer i__1;
extern integer i__;
extern real swap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and reorganizing accesses to improve spatial locality
    // Instead of accessing sr[i__], sr[i__+1], sr[i__+2] in scattered fashion, we process two iterations at once
    // with more sequential access patterns when possible. We assume i__1 is odd for simplicity.
    integer start = 1;
    integer end = i__1 - 1; // Ensure we don't go out of bounds on i__+2

    for (i__ = start; i__ <= end; i__ += 2) {
        integer idx1 = i__;
        integer idx2 = i__ + 1;

        real si1 = si[idx1];
        real si2 = si[idx2];

        if (si1 != -si2) {
            real sr1 = sr[idx1];
            real sr2 = sr[idx2];
            real sr3 = sr[idx2 + 1]; // i__+2

            // Sequential write-back with rotation
            sr[idx1]     = sr2;
            sr[idx2]     = sr3;
            sr[idx2 + 1] = sr1;

            real si3 = si[idx2 + 1];
            si[idx1]     = si2;
            si[idx2]     = si3;
            si[idx2 + 1] = si1;
        }
    }
}
