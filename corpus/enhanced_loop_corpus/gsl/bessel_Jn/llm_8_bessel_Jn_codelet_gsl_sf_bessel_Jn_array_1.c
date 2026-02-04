#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmin;
extern int nmax;
extern double *result_array;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = nmax; n >= nmin; n--) {
        double sum = 0.0;
        for (int i = 0; i < 5; i++) {
            sum += (double)(i * n) / (n + 1);
        }
        result_array[n - nmin] = sum;
    }
}
