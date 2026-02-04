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
    // Variant 2: Strided memory access with increasing stride
    // Simulate non-unit stride access pattern: access every 2nd element in reverse, then fill gaps
    // First pass: process elements with even indices in reverse (strided access)
    for (i = (len - 1) & ~1; i > 0; i -= 2) {
        if (i < len) {
            double tmp = c[i - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
            ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
            ans.dat[0] = tmp;
        }
    }
    // Second pass: process odd-indexed elements in reverse (completes full coverage)
    for (i = (len - 1) | 1; i > 0; i -= 2) {
        if (i < len && i > 0) {
            double tmp = c[i - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
            ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
            ans.dat[0] = tmp;
        }
    }
}
