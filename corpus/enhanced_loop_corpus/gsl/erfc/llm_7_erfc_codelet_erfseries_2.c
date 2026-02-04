#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double coef;
extern double e;
extern double del;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_e = e;
    for (k = 1; k < 30; ++k) {
        double new_coef = coef * -x * x / k;
        double new_del = new_coef / (2. * k + 1.);
        local_e += new_del;
        coef = new_coef;
    }
    e = local_e;
}
