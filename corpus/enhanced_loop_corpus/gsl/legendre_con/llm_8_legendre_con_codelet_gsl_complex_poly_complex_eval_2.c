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
    for (i = len - 1; i > 0; i -= 2) {
        double tmp1, tmp2;
        gsl_complex prev_c1 = c[i - 1];
        gsl_complex prev_c2;
        if (i >= 2) prev_c2 = c[i - 2];

        // First iteration unrolled: process i-1
        tmp1 = prev_c1.dat[0] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = prev_c1.dat[1] + z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp1;

        // Second iteration (if valid): process i-2
        if (i >= 2) {
            tmp2 = prev_c2.dat[0] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
            ans.dat[1] = prev_c2.dat[1] + z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
            ans.dat[0] = tmp2;
        }
    }
}
