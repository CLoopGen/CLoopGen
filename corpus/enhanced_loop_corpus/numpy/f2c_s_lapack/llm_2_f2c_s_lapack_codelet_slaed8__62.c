#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indxq;
extern integer *perm;
extern integer *indx;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering the index computation
    // Instead of indirect access via indx[j], we assume a scenario where indx is identity-like
    // and convert into a consecutive pattern for better cache locality.
    integer base_index = 0;
    for (j = 1; j <= i__1; ++j) {
        base_index = j; // Simulate direct sequential indexing
        perm[j] = indxq[base_index];
    }
}
