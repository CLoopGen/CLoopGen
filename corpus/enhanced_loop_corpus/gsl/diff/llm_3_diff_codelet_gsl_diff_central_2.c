#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern double a[4];
extern double d[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reversed access with offset base
    // Change access pattern to process elements in reverse order,
    // using consecutive indexing from the end of valid range to improve cache locality.
    for (k = 1; k < 5; k++) {
        int limit = 4 - k;
        // Process from the last valid index down to 0 for better backward cache usage
        for (i = limit - 1; i >= 0; i--) {
            // Maintain same computation but reverse iteration order
            d[i] = (d[i + 1] - d[i]) / (a[i + k] - a[i]);
        }
    }
}
