#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp *strides;
int nargs;
char **dataptrs;
Py_ssize_t subloopsize;

void init_vars() {
    nargs = 4;
    subloopsize = 1000000; // 1M elements per subloop

    strides = (npy_intp*)malloc(nargs * sizeof(npy_intp));
    dataptrs = (char**)malloc(nargs * sizeof(char*));

    size_t data_size = subloopsize * sizeof(double); 

    for (int i = 0; i < nargs; i++) {
        strides[i] = sizeof(double);
        dataptrs[i] = (char*)malloc(data_size);
    }
}