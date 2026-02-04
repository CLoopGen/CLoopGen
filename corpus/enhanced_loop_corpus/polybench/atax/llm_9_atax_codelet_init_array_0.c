#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x[2100];
extern int i;
extern double fn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double inv_fn = 1.0 / fn;
    double offset = 1.0;
    for (i = 0; i < n; i++) {
        double index_d = (double)i;
        x[i] = offset + index_d * inv_fn;
    }
}
