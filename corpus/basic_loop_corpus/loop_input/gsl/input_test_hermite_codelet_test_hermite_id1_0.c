#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n;
double y;
double *a;
double *b;
int k;

void init_vars() {
    n = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
    y = 2.0;
    
    a = (double*)calloc(n + 1, sizeof(double));
    b = (double*)calloc(n + 1, sizeof(double));
    
    if (!a || !b) {
        exit(1);
    }
    
    a[0] = 1.0;
    b[0] = 1.0;
}