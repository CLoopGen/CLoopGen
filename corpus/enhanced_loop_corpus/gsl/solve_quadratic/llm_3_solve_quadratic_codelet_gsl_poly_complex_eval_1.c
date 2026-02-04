#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double dat[2];
} gsl_complex;

extern  double c[];
extern  int len;
extern  gsl_complex z;
extern int i;
extern gsl_complex ans;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect access via precomputed indices (common in sparse or permuted data patterns)
    // We simulate an index map: indices[i] = len - 1 - i, but accessed in forward loop order
    // This reverses access order just like original, but through an indirection table

    // Assuming existence of a precomputed index array `indices` of size len
    // Since we cannot modify global declarations, we simulate it locally with alloca or fixed stack
    int* indices = (int*)alloca(len * sizeof(int));
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j;  // maps forward index to reverse position
    }

    // Now traverse from i = len-1 down to 1 indirectly
    for (i = 0; i < len - 1; i++) {  // i now used as index into indices
        int pos = indices[i];        // gives decreasing values: len-1, len-2, ..., 1
        if (pos <= 0) break;

        double tmp = c[pos - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }
}
