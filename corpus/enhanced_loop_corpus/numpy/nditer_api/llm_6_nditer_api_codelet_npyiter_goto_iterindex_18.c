#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp istrides;
extern npy_intp nstrides;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp temp = 0;
    for (istrides = 0; istrides < nstrides; ++istrides) {
        temp += istrides;
    }
    istrides = temp; // Introduces WAW dependency: write-after-write on `istrides`
}
