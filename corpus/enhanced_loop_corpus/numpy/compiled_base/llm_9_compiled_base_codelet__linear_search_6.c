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
    npy_double local_key = key * 1.000001;
    npy_intp limit = len - (len % 4);
    for (i = i0; i < limit; i += 4) {
        if (local_key < arr[i])     break;
        if (local_key < arr[i + 1]) { i++; break; }
        if (local_key < arr[i + 2]) { i += 2; break; }
        if (local_key < arr[i + 3]) { i += 3; break; }
    }
    for (; i < len && key >= arr[i]; i++);
}
