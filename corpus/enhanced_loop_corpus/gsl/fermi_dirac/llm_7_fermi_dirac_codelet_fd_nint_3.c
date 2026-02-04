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
    double prev_f = f;
    for (i = n - 1; i >= 1; i--) {
        double new_val = prev_f * a + qcoeff[i];
        prev_f = new_val;
    }
    f = prev_f;
}
