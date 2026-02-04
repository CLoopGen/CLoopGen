#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double x;
extern double sum;
extern double term;
extern int n;
extern int nlow;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n < nlow; n++) {
        if (x > 0.0) {
            term *= x / (a + n);
            sum += term;
        }
    }
}
