#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with precomputed indices)
    // Since we cannot redefine data structures, simulate indirect addressing via arithmetic
    // Access elements in reverse order but through offset calculation (quasi-indirect)
    UInt32 indices[16385];
    int len = 0;
    for (i = 65536; i >= 0; i -= 4) {
        indices[len++] = i;
    }
    // Now traverse indirectly
    for (int j = 0; j < len; j++) {
        i = indices[j];
        ftab[i] = 0;
        if (i >= 1) ftab[i-1] = 0;
        if (i >= 2) ftab[i-2] = 0;
        if (i >= 3) ftab[i-3] = 0;
    }
}
