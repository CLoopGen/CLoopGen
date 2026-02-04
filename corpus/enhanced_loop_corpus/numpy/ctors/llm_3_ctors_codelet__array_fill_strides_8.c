#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef unsigned char npy_bool;

extern  npy_intp *dims;
extern int nd;
extern int i;
extern npy_bool not_cf_contig;
extern npy_bool nod;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp indices[16]; // Assuming maximum dimensions is 16
    for (i = 0; i < nd; i++) {
        indices[i] = 0;
    }
    for (i = 0; i < nd; i++) {
        if (*(dims + i) != 1) { // Indirect-like access using pointer arithmetic
            if (nod) {
                not_cf_contig = 1;
                break;
            }
            nod = 1;
        }
    }
}
