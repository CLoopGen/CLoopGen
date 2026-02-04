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
    // Variant 2: Indirect memory access via index array (simulated with offset arithmetic)
    npy_intp *indices = (npy_intp*)malloc(sizeof(npy_intp) * len);
    if (!indices) return;
    for (npy_intp idx = 0; idx < len; idx++) {
        indices[idx] = idx; // identity mapping for indirect access
    }
    for (i = i0; i < len && key >= arr[indices[i]]; i++)
        ;
    free(indices);
}
