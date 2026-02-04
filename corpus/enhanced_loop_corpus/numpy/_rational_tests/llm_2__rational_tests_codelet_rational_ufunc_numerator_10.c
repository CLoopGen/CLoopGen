#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef struct {
    int n;
    int dmm;
} rational;

extern npy_intp is;
extern npy_intp os;
extern npy_intp n;
extern char *i;
extern char *o;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    npy_intp i_stride = is / sizeof(rational);
    rational *i_ptr = (rational *)i;
    for (k = 0; k < n - 1; k += 2) {
        rational x1 = i_ptr[k];
        rational x2 = i_ptr[k + 1];
        o += os * 2;
    }
    // Handle remaining element if n is odd
    if (k < n) {
        rational x = i_ptr[k];
        o += os;
    }
}
