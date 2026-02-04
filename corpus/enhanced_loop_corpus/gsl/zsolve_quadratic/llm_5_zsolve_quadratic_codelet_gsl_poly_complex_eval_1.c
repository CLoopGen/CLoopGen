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
    for (i = len - 1; i > 0; i--) {
        double re_part = ans.dat[0];
        double im_part = ans.dat[1];
        double factor = (z.dat[0] + z.dat[1]) * 0.5;

        if (factor > 1e-6) {
            ans.dat[0] = c[i - 1] + z.dat[0] * re_part - z.dat[1] * im_part;
            ans.dat[1] = z.dat[1] * re_part + z.dat[0] * im_part;
        } else {
            ans.dat[0] = c[i - 1];
            ans.dat[1] = 0.0;
        }
    }
}
