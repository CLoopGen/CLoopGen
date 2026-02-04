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
    npy_intp outer_i;
    for (outer_i = 0; outer_i < lena; outer_i++) {
        if (outer_i == 0) continue;
        for (i = outer_i; (i < lena) && (a[i] == last); i++) {
            break;
        }
        i = outer_i;
        break;
    }
}
