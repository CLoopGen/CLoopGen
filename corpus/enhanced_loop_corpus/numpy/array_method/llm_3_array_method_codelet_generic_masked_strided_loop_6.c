#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_intp *strides;
extern int nargs;
extern char **dataptrs;
extern Py_ssize_t subloopsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reverse iteration to modify access pattern
    for (int i = nargs - 1; i >= 0; i--) {
        dataptrs[i] = dataptrs[i] + strides[i] * subloopsize;
    }
}
