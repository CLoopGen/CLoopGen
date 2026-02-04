#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double y;
extern  int M;
extern double sum;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum = 0.0;
    int limit = M > 1000 ? M / 2 : M;
    for (n = 1; n <= limit; n++) {
        double term1 = 1.0 / (n * (n * n + y * y));
        double term2 = 1.0 / ((n + M) * ((n + M) * (n + M) + y * y));
        local_sum += term1 + term2;
    }
    sum += local_sum;
}
