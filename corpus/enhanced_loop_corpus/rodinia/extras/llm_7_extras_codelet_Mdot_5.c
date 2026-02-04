#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *x;
extern double *y;
extern int i;
extern int len4;
extern double sum0;
extern double sum1;
extern double sum2;
extern double sum3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len4; i++) {
        double prod0 = x[4 * i] * y[4 * i];
        double prod1 = x[4 * i + 1] * y[4 * i + 1];
        double prod2 = x[4 * i + 2] * y[4 * i + 2];
        double prod3 = x[4 * i + 3] * y[4 * i + 3];
        
        sum0 = sum0 + prod0;
        sum1 = sum0 + prod1;  // WAW and WAR dependency introduced: sum1 depends on updated sum0
        sum2 = sum1 + prod2;  // chain of dependencies across accumulators
        sum3 = sum2 + prod3;
    }
}
