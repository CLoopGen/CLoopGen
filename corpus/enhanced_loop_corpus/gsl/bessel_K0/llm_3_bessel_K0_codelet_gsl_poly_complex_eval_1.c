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
    // Simulate indirect access via an auxiliary index array that reverses traversal order
    int *indices = (int*)malloc(len * sizeof(int));
    if (!indices) return;
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j;  // reverse order indices
    }
    for (int j = 0; j < len - 1; j++) {
        i = indices[j];
        if (i <= 0) continue;
        double tmp = c[i - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }
    free(indices);
}
