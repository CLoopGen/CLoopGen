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
    for (j = 0; j < 1; j++) {
        for (i = 1; (i < lena) && (a[i] == last); i++)
            ;
    }
}
