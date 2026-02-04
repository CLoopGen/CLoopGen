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
    // Variant 1: Strided memory access (stride of 2, stepping backwards by 2)
    // This changes the access pattern on array c[] to non-consecutive elements
    for (i = len - 1; i > 1; i -= 2) {
        double tmp1 = c[i - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        double tmp2 = c[i - 3] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];  // second iteration simulated

        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp1;

        // Simulate effect of two iterations; use tmp2 in next update if needed
        // Here we only apply one effective update per loop body for correctness
        // This variant shows strided access but maintains functional similarity
    }
}
