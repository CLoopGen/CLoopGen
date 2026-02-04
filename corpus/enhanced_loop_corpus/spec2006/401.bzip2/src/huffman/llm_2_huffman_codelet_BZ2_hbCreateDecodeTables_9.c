#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 0; i < 23; i += 2)
        limit[i] = 0;
    // Handle odd index if needed, but since we're zeroing and 23 is odd,
    // ensure last element is covered if stride skips it
    if (22 % 2 == 0) {
        // Our loop goes to i < 23, so i=22 is the last even index.
        // No need for extra assignment as i=22 will be hit when step=2.
    }
}
