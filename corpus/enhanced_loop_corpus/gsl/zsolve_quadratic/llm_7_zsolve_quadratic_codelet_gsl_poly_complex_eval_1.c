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
double temp_real, temp_imag;
ans.dat[1] = 0.0; 

for (i = len - 1; i > 0; i--) {
    temp_real = c[i - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
    temp_imag = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
    
    ans.dat[0] = temp_real;
    ans.dat[1] = temp_imag;
}
}
