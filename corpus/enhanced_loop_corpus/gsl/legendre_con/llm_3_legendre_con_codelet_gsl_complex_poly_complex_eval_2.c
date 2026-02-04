#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double dat[2];
} gsl_complex;

extern  gsl_complex c[];
extern  int len;
extern  gsl_complex z;
extern int i;
extern gsl_complex ans;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive Forward Access with Index Remapping (simulate reversed order via indexing)
    int* indices = (int*)malloc(len * sizeof(int));
    if (!indices) return; // Handle malloc failure
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j; // Reverse index mapping
    }
    for (i = 1; i < len; i++) {
        int idx = indices[i]; // Map to original reverse iteration index
        if (idx - 1 < 0) continue;
        double tmp = c[idx - 1].dat[0] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = c[idx - 1].dat[1] + z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }
    free(indices);
}
