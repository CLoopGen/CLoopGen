#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    int x;
    int temp = y * 2; // Move invariant computation out of inner loop (WAW reduction)
    for (x = 0; x < 8; x++) {
        int ref;
        int cur = temp + x;
        ref = cur + 1;  // Create local WAW: ref written after use in logic (though no reuse)
        cur = ref * 2;  // Re-write cur creates WAW dependence within iteration
        // Eliminate cross-iteration dependencies: all operations are independent across iterations
        // No loop-carried dependencies; both loops are now fully parallelizable
    }
}
}
