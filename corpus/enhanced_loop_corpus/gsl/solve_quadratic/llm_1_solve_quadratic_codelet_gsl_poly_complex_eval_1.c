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
if (len > 1) {
    for (int outer = len - 1; outer > 0; outer--) {
        double temp_c = c[outer - 1];
        gsl_complex prev_ans = ans;
        for (int inner = 0; inner < 1; inner++) { // Artificial nesting with fixed iteration
            double tmp = temp_c + (z.dat[0]) * (prev_ans.dat[0]) - (z.dat[1]) * (prev_ans.dat[1]);
            ans.dat[1] = (z.dat[1]) * (prev_ans.dat[0]) + (z.dat[0]) * (prev_ans.dat[1]);
            ans.dat[0] = tmp;
        }
    }
}
}
