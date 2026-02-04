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
    for (i = 0; i < nd; i++) {
        npy_bool is_not_one = (dims[i] != 1);
        if (!is_not_one) continue;
        not_cf_contig = nod ? 1 : not_cf_contig;
        if (nod) break;
        nod = 1;
    }
}
