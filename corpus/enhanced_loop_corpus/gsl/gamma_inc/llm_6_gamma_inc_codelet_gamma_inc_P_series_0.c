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
    double temp_sum = sum;
    double temp_term = term;
    for (n = 1; n < nlow; n++) {
        temp_term = temp_term * x / (a + n);
        temp_sum = temp_sum + temp_term;
    }
    sum = temp_sum;
    term = temp_term;
}
