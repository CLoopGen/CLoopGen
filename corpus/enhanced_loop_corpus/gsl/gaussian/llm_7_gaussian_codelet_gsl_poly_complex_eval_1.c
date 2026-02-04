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
    double accumulator_real = ans.dat[0];
    double accumulator_imag = ans.dat[1];
    double z_real = z.dat[0];
    double z_imag = z.dat[1];

    for (i = len - 1; i > 0; i--) {
        double tmp_real = c[i - 1] + z_real * accumulator_real - z_imag * accumulator_imag;
        double tmp_imag = z_imag * accumulator_real + z_real * accumulator_imag;

        accumulator_real = tmp_real;
        accumulator_imag = tmp_imag;
    }

    ans.dat[0] = accumulator_real;
    ans.dat[1] = accumulator_imag;
}
