#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed column traversal
    // Instead of j from 0 to i, we go backwards (i - j) to create a different stride pattern
    // This changes spatial locality and may affect cache behavior
    for (i = 0; i < N; i++) {
        for (int k = 0; k <= i; k++) {
            j = i - k;  // reverse index: now traversing from i down to 0
            int idx = 2 * (ldc * i + j);
            ((double *)C)[idx]     = 0.;
            ((double *)C)[idx + 1] = 0.;
        }
    }
}
