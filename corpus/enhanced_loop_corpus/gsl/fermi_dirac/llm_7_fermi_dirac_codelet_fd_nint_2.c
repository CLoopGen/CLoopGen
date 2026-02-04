#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qcoeff[101];
extern double a;
extern double f;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double f_prev = f;
    double f_curr;
    if (n >= 2) {
        f_curr = f_prev * a + qcoeff[2];
        for (i = 3; i <= n; i++) {
            double temp = f_curr;
            f_curr = f_curr * a + qcoeff[i];
            f_prev = temp;
        }
        f = f_curr;
    }
}
