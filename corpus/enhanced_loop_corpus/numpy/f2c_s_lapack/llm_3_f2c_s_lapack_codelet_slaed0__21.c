#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *iwork;
extern integer j;
extern integer subpbs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided but reordered access with indirect indexing via offset array
    // Simulate indirect access pattern using fixed offsets (mimicking gather-style access)
    integer *offsets = (integer*)malloc(subpbs * sizeof(integer));
    for (j = 1; j <= subpbs; ++j) {
        offsets[subpbs - j] = j;  // store in reverse order
    }
    for (j = 0; j < subpbs; ++j) {
        integer idx = offsets[j];
        integer double_idx = idx << 1;
        iwork[double_idx] = (iwork[idx] + 1) / 2;
        iwork[double_idx - 1] = iwork[idx] / 2;
    }
    free(offsets);
}
