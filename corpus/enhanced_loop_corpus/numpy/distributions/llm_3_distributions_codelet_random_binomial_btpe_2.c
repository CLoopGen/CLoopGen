#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double a;
extern double s;
extern double F;
extern int64_t m;
extern int64_t y;
extern int64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access using an index array (simulating indirect memory access)
    // Precompute an array of indices to traverse in arbitrary order (e.g., reverse order)
    int64_t *indices = (int64_t*)malloc(sizeof(int64_t) * (y - m));
    if (!indices) exit(1);
    int64_t len = y - m;
    for (int64_t j = 0; j < len; j++) {
        indices[j] = y - j; // reverse order access
    }
    for (int64_t j = 0; j < len; j++) {
        int64_t idx = indices[j];
        if (idx >= m + 1 && idx <= y) {
            F *= (a / idx - s);
        }
    }
    free(indices);
}
