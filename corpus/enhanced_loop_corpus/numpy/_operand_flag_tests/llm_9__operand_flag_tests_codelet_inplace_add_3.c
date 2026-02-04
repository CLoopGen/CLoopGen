#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp i;
extern npy_intp n;
extern char *in1;
extern char *in2;
extern npy_intp in1_step;
extern npy_intp in2_step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        npy_intp *val1 = (npy_intp *)in1;
        npy_intp *val2 = (npy_intp *)in2;
        *val1 = *val1 + *val2 + (*val2 >> 1) - (*val1 >> 2);
        in1 += in1_step;
        in2 += in2_step;
    }
}
