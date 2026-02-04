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
    double tmp2 = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
    if (i - 1 > 0) {
        double tmp_next = c[i - 2] + z.dat[0] * tmp1 - z.dat[1] * tmp2;
        ans.dat[1] = z.dat[1] * tmp1 + z.dat[0] * tmp2;
        ans.dat[0] = tmp_next;
    } else {
        ans.dat[1] = tmp2;
        ans.dat[0] = tmp1;
    }
}
}
