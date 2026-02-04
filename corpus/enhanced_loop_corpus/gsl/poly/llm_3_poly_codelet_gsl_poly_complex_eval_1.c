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
    // Variant 2: Consecutive forward traversal with indirect indexing via an index array
    // Simulate indirect access using a precomputed index map (emulated here with reverse order)
    int *indices = (int*)malloc(len * sizeof(int));
    if (!indices) return; // Handle allocation failure
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j; // Reverse index mapping
    }
    for (i = 1; i < len; i++) {
        int idx = indices[i]; // Indirect access through index array
        if (idx == 0) continue; // Skip first coefficient if needed
        double tmp = c[idx - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }
    free(indices);
}
