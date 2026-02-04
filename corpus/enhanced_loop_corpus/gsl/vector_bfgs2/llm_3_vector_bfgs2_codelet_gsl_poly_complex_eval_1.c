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
    // Variant 2: Reverse consecutive access with temporary accumulation
    // Instead of updating ans directly, use local variables to enable potential vectorization
    // and reverse the access pattern by iterating forward through reversed index mapping
    double accum_real = ans.dat[0];
    double accum_imag = ans.dat[1];

    for (int j = 0; j < len - 1; j++) {
        int i = len - 1 - j;  // Reverse index mapping
        double tmp = c[i - 1] + z.dat[0] * accum_real - z.dat[1] * accum_imag;
        accum_imag = z.dat[1] * accum_real + z.dat[0] * accum_imag;
        accum_real = tmp;
    }

    ans.dat[0] = accum_real;
    ans.dat[1] = accum_imag;
}
