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
    // Variant 1: Strided memory access (stride of 2, assuming len allows it)
    // This variant accesses c[i - 1] with a stride of 2, processing every other element
    // We adjust the loop bounds accordingly to prevent out-of-bounds access
    int stride = 2;
    for (i = len - 1; i > 0; i -= stride) {
        if (i - 1 < 0) break;
        double tmp = c[i - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }
}
