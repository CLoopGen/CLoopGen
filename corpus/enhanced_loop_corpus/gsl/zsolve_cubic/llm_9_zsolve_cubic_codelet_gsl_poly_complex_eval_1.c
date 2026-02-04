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
    double factor_r = z.dat[0];
    double factor_i = z.dat[1];
    double a_r = ans.dat[0];
    double a_i = ans.dat[1];

    for (i = len - 1; i > 0; i--) {
        double tmp = c[i - 1] + factor_r * a_r - factor_i * a_i;
        a_i = factor_i * a_r + factor_r * a_i;
        a_r = tmp;
    }

    ans.dat[0] = a_r;
    ans.dat[1] = a_i;
}
