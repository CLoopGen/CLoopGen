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
        if (dims[i] != 1) {
            for (int j = 0; j < 1; j++) {  // Artificially increased nesting depth
                if (nod) {
                    not_cf_contig = 1;
                    break;
                }
                nod = 1;
            }
            break;
        }
    }
}
