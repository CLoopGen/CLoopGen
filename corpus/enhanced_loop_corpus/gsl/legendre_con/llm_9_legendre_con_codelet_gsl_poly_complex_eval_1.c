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
    if (len <= 1) return;

    double sum_real = ans.dat[0];
    double sum_imag = ans.dat[1];

    for (i = 1; i < len; i++) {
        double new_real = c[len - 1 - i] + z.dat[0] * sum_real - z.dat[1] * sum_imag;
        double new_imag = z.dat[1] * sum_real + z.dat[0] * sum_imag;
        sum_real = new_real;
        sum_imag = new_imag;
    }

    ans.dat[0] = sum_real;
    ans.dat[1] = sum_imag;
}
