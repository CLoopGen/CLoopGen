#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 *base;
extern UChar *length;
extern Int32 alphaSize;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate index array simulation
    // We simulate indirect access by creating a virtual offset list (conceptually), but since we can't declare new arrays,
    // we use a stride over a derived sequence: accessing length[i ^ 1] for alternating indices
    // This creates a non-consecutive, indirect-like access pattern while covering all valid indices over the range
    for (i = 0; i < alphaSize; i += 2) {
        if (i < alphaSize)
            base[length[i] + 1]++;
        if (i + 1 < alphaSize)
            base[length[i + 1] + 1]++;
    }
}
