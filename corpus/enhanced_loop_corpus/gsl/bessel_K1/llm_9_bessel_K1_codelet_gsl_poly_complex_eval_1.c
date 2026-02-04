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
    int stride = 4;
    for (i = len - 1; i > 0; i--) {
        double real_part = ans.dat[0];
        double imag_part = ans.dat[1];
        double z_real = z.dat[0];
        double z_imag = z.dat[1];

        for (int j = 0; j < stride; j++) {
            double new_real = c[(i - 1 + j) % len] + z_real * real_part - z_imag * imag_part;
            double new_imag = z_imag * real_part + z_real * imag_part;
            real_part = new_real;
            imag_part = new_imag;
        }

        ans.dat[0] = real_part;
        ans.dat[1] = imag_part;
    }
}
