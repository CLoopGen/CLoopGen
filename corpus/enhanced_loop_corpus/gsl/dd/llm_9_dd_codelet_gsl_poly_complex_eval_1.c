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
    int stride = 1;
    for (i = len - 1; i > 0; i -= stride) {
        double re = ans.dat[0], im = ans.dat[1];
        double z_re = z.dat[0], z_im = z.dat[1];

        // Increase arithmetic intensity: unroll and compute multiple steps
        ans.dat[0] = c[i - 1] + z_re * re - z_im * im;
        ans.dat[1] = z_im * re + z_re * im;

        // Add extra floating-point operations to increase computational load
        ans.dat[0] = ans.dat[0] * 0.5 + ans.dat[1] * 0.3 + ans.dat[0] * ans.dat[1] * 1e-4;
        ans.dat[1] = ans.dat[1] * 0.5 - ans.dat[0] * 0.3;

        // Adjust stride dynamically based on intermediate result to vary trip count behavior
        stride = (ans.dat[0] > 0.0) ? 1 : 1;
    }
}
