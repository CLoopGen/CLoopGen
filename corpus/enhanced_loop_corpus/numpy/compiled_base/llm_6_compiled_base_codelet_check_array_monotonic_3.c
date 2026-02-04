#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  double *a;
extern npy_intp lena;
extern npy_intp i;
extern double last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp j;
    double temp_last = last;
    for (i = 1; (i < lena) && (a[i] == temp_last); i++) {
        temp_last = a[i-1]; // Introduce a WAW and RAW dependency: current iteration writes to temp_last, next reads it
    }
}
