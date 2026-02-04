#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int numnew;
extern npy_intp *mydim;
extern int i;
extern npy_intp tempsize;
extern npy_intp *mystrides;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping table (simulating non-trivial access pattern)
    npy_intp indices[numnew];
    for (i = 0; i < numnew; i++) {
        indices[i] = numnew - 1 - i;  // Reverse index map
    }
    tempsize = 1;
    for (i = 0; i < numnew; i++) {
        npy_intp mapped_idx = indices[i];
        mystrides[mapped_idx] = tempsize;
        tempsize *= (mydim[mapped_idx] != 0) ? mydim[mapped_idx] : 1;
    }
}
