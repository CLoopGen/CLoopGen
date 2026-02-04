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
for (i = len - 1; i > 0; i -= 2) {
    double tmp1 = c[i - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
    double tmp2 = (i > 1) ? c[i - 2] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1] : tmp1;
    
    double imag1 = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
    double imag2 = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
    
    ans.dat[1] = imag1;
    ans.dat[0] = tmp1;

    if (i > 1) {
        ans.dat[1] = imag2;
        ans.dat[0] = tmp2;
    }
}
}
