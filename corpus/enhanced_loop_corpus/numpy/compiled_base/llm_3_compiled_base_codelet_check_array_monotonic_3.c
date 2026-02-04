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
    // Variant 2: Consecutive reverse traversal from the end
    for (i = lena - 1; (i >= 1) && (a[i] == last); i--)
        ;
}
