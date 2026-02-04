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
if (len <= 1) return;
double a = ans.dat[0];
double b = ans.dat[1];
for (i = len - 1; i > 0; i--) {
    double new_a = c[i - 1] + z.dat[0] * a - z.dat[1] * b;
    double new_b = z.dat[1] * a + z.dat[0] * b;
    a = new_a;
    b = new_b;
}
ans.dat[0] = a;
ans.dat[1] = b;
}
