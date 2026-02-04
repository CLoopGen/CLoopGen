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



void loop(){
    double accum_real = ans.dat[0];
    double accum_imag = ans.dat[1];
    double z_real = z.dat[0];
    double z_imag = z.dat[1];

    for (i = len - 1; i > 0; i--) {
        double new_real = c[i - 1] + z_real * accum_real - z_imag * accum_imag;
        double new_imag = z_imag * accum_real + z_real * accum_imag;
        
        accum_real = new_real;
        accum_imag = new_imag;
    }

    ans.dat[0] = accum_real;
    ans.dat[1] = accum_imag;
}
