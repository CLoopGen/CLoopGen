#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *p;
extern double *q;
extern size_t n;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t j;
    double temp;
    for (j = 0; j < (ssize_t)n; j++) {
        temp = p[j];
        q[j] = temp;
    }
}
