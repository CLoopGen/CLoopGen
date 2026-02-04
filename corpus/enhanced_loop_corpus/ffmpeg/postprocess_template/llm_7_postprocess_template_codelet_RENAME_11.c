#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    int x;
    int temp = y * 2; // Move computation outside inner loop to create loop-carried dependence on y
    for (x = 0; x < 8; x++) {
        int ref;
        int cur = temp + x; // Eliminate direct dependence on y inside inner loop; use precomputed temp
        ref = cur - x;      // Create anti-dependence (WAR): ref is written after cur uses x
        // No loop-carried data dependence in inner loop due to removal of cross-iteration dependencies
    }
    y += 1; // Artificially modify loop index (though still controlled by for-loop increment)
}
}
