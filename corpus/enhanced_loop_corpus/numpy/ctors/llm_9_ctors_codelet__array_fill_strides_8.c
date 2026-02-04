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
    npy_intp step = (nd > 4) ? 2 : 1;  // Adjust trip count based on condition
    for (i = 0; i < nd; i += step) {
        // Unrolled check to increase computational density
        if (i < nd && dims[i] != 1) {
            if (nod) {
                not_cf_contig = 1;
                break;
            }
            nod = 1;
        }
        // Simulate partial unrolling with bounds check
        npy_intp next = i + 1;
        if (step == 1 && next < nd && dims[next] != 1) {
            if (nod) {
                not_cf_contig = 1;
                break;
            }
            nod = 1;
        }
    }
}
