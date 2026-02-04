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
    for (int i = 0; i < 2; i++) {
        for (n = 1; n < nlow; n++) {
            term *= x / (a + n);
            sum += term;
        }
    }
}
