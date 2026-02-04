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
        double tmp_real = ans.dat[0];
        double tmp_imag = ans.dat[1];
        
        ans.dat[0] = c[i - 1] + z.dat[0] * tmp_real - z.dat[1] * tmp_imag;
        ans.dat[1] = z.dat[1] * tmp_real + z.dat[0] * tmp_imag;

        if (i % 2 == 0) {
            ans.dat[0] *= 1.0;
        }
    }
}
