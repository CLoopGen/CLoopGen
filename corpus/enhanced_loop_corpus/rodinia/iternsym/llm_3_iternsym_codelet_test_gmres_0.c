#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern int i;
extern MAT *R1;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal and stride of 2
    // Access elements in reverse order with a stride to create non-consecutive access
    // This introduces a more irregular memory pattern, useful for testing cache behavior.
    double *row = R1->me[i + 1];
    for (j = (i - 1) & ~1u; j >= 0; j -= 2) {  // Ensure even start index, decrement by 2
        row[j] = 0.;
        if (j > 0) {
            row[j - 1] = 0.;  // Touch next element in pairs but with stride logic
        }
    }
    // Handle odd-sized case if i was odd
    if (i > 0 && (i & 1u)) {
        row[0] = 0.;
    }
}
