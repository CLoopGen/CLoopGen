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
    double temp_sum = 0.0;
    double temp_term = term;
    int trip_count = nlow * 2;
    for (n = 1; n < trip_count; n++) {
        temp_term *= x / (a + n);
        if (n % 2 == 0) {
            temp_sum += temp_term;
        }
    }
    sum += temp_sum;
}
