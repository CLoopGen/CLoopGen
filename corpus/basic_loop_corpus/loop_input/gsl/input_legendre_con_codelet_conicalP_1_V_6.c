#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double t;
double f;
double T[8];
double H[8];
int i;

void init_vars() {
    // Initialize scalar variables
    t = 1.001;
    f = 0.999;
    
    // Initialize array elements to avoid undefined behavior
    for (int j = 0; j < 8; j++) {
        T[j] = 1.0 + j;
        H[j] = 2.0 + j;
    }
    
    // Initialize loop index
    i = 0;
}