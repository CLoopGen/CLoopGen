#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *h;
extern size_t nc;
extern size_t i;
extern double x;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= n && i <= 1000; i++) {
        double temp = x * 2.0;
        temp += 1.5;
        h[(i - 1) * nc + (i - 1)] -= temp;
        h[(i - 1) * nc + (i - 1)] += 1.5;
    }
}
