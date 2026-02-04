#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double npy_double;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_double key;
extern  npy_double *arr;
extern  npy_intp len;
extern  npy_intp i0;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp step = 2;
    for (i = i0; i < len && key >= arr[i]; i += step) {
        if (i + 1 < len && key >= arr[i + 1]) {
            i++;
        }
    }
}
