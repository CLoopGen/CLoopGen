#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int active_caches[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with reversed order (backward traversal)
    for (int k = 1; k >= 0; k--) {
        active_caches[k] = 0;
    }
}
