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
    double temp_real = ans.dat[0];
    double temp_imag = ans.dat[1];
    double zr = z.dat[0];
    double zi = z.dat[1];

    for (i = len - 1; i > 0; i--) {
        double new_real = c[i - 1] + zr * temp_real - zi * temp_imag;
        double new_imag = zi * temp_real + zr * temp_imag;

        temp_real = new_real;
        temp_imag = new_imag;
    }

    ans.dat[0] = temp_real;
    ans.dat[1] = temp_imag;
}
