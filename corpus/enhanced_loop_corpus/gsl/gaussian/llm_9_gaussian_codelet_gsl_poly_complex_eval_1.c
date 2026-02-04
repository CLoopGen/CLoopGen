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
    double acc_real = ans.dat[0], acc_imag = ans.dat[1];
    for (i = len - 1; i > 0; i--) {
        double new_real = c[i - 1] + z.dat[0] * acc_real - z.dat[1] * acc_imag;
        double new_imag = z.dat[1] * acc_real + z.dat[0] * acc_imag;
        acc_real = new_real;
        acc_imag = new_imag;
    }
    ans.dat[0] = acc_real;
    ans.dat[1] = acc_imag;
}
