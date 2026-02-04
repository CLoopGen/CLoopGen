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
        double real_ans = ans.dat[0];
        double imag_ans = ans.dat[1];
        double z_real = z.dat[0];
        double z_imag = z.dat[1];
        
        ans.dat[0] = c[i - 1] + z_real * real_ans - z_imag * imag_ans;
        ans.dat[1] = z_imag * real_ans + z_real * imag_ans;
    }
}
