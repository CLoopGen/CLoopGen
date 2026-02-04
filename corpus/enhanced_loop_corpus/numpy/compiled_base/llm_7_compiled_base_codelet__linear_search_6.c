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
    npy_double prev_val = (i0 > 0) ? arr[i0 - 1] : key;
    for (i = i0; i < len; i++) {
        npy_double curr_val = arr[i];
        if (key < curr_val) {
            break;
        }
        // Add artificial dependency: current iteration depends on previous value
        // Introduce loop-carried RAW dependency via prev_val (though not affecting logic)
        prev_val = curr_val; // Maintain state to create a carried dependency
    }
    // Semantics preserved: exit when key < arr[i], equivalent to original condition
}
