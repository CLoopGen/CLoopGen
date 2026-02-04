#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index lookup table
    // Simulate indirect access via precomputed indices in reverse order.
    // Since we cannot introduce new global storage beyond what's declared,
    // we simulate indirect access with arithmetic without extra arrays.

    // Use indirect-like indexing: reverse traversal through a transformed index
    // Here, we use a simple inversion: map linear descending index to itself indirectly
    // This mimics indirect access patterns common in gather operations.
    Int32 idx;
    for (i = 65537; i >= 1; i--) {
        idx = 65536 - (65537 - i); // indirect calculation equivalent to i-1
        ftab[idx] = 0;
    }
}
