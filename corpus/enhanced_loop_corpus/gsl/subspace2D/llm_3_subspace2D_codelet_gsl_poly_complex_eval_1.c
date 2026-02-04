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
    // Variant 2: Strided memory access with stride of 2 (simulating irregular or reduced frequency access)
    // We modify the loop to step by 2 in reverse, adjusting bounds accordingly.
    // This changes data dependency and access pattern to strided.

    for (i = (len % 2 == 1) ? len - 1 : len - 2; i > 0; i -= 2) {
        double tmp = c[i - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }
}
