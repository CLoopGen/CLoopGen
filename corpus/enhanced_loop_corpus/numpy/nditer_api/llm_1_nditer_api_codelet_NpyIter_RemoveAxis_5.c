#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int iop;
extern int nop;
extern npy_intp *strides;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nop > 0) {
        for (iop = 0; iop < nop; ++iop) {
            for (int inner = 0; inner < 1; ++inner) {
                strides[iop] = 0;
            }
        }
    }
}
