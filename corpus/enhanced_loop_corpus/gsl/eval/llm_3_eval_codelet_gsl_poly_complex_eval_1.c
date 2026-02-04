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
    // Variant 2: Indirect Memory Access using an index map (simulated with stride reversal)
    int* indices = (int*)malloc(len * sizeof(int));
    if (!indices) return;
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j;  // reverse index mapping
    }
    for (i = 0; i < len - 1; i++) {
        int mapped_idx = indices[i];
        if (mapped_idx == 0) continue;
        double tmp = c[mapped_idx - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }
    free(indices);
}
