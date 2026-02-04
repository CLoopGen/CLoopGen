#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int n;
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with reversed read access pattern
    int idx;
    int limit = n - order;
    for (i = 0; i < limit; i++) {
        idx = n - 1 - i;  // reverse index from end of array
        if (idx > order) {
            res[idx] = smp[idx] - smp[idx - 1];
        }
    }
    // Ensure the original starting point is covered if not handled
    if (order < n) {
        res[order] = smp[order] - smp[order - 1];
    }
}
