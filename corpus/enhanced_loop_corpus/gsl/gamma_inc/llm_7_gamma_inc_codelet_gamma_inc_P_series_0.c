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
    double local_a = a;
    double local_x = x;
    double local_sum = sum;
    double local_term = term;
    int local_nlow = nlow;

    for (n = 1; n < local_nlow; n++) {
        double factor = local_x / (local_a + n);
        local_term *= factor;
        if (n % 2 == 0) {
            local_sum += local_term;
        }
    }

    sum = local_sum;
    term = local_term;
}
