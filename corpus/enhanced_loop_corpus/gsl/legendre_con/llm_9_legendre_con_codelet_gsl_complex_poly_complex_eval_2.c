#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double dat[2];
} gsl_complex;

extern  gsl_complex c[];
extern  int len;
extern  gsl_complex z;
extern int i;
extern gsl_complex ans;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    double real_acc = ans.dat[0];
    double imag_acc = ans.dat[1];
    int step = (len > 1000) ? 4 : 1; // Increase computational intensity for large inputs

    for (i = len - 1; i > 0; i -= step) {
        for (int j = 0; j < step && (i - j) > 0; j++) {
            double new_real = c[i - 1 - j].dat[0] + z.dat[0] * real_acc - z.dat[1] * imag_acc;
            double new_imag = c[i - 1 - j].dat[1] + z.dat[1] * real_acc + z.dat[0] * imag_acc;
            real_acc = new_real;
            imag_acc = new_imag;
        }
    }
    ans.dat[0] = real_acc;
    ans.dat[1] = imag_acc;
}
