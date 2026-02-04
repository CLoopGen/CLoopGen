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
    // Variant 2: Indirect (gather-style) memory access using an index map
    // Simulate indirect access via an auxiliary index array (emulated with arithmetic)
    int* indices = (int*)malloc(len * sizeof(int));
    if (!indices) return; // handle malloc failure gracefully

    // Create reverse order index map (still covers all elements, but accessed indirectly)
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j;
    }

    for (int idx = 0; idx < len - 1; idx++) {
        i = indices[idx]; // current index from indirect map
        if (i <= 0) continue;

        int prev_index = indices[idx + 1]; // previous element in reversed sequence
        double tmp = c[prev_index] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }

    free(indices);
}
