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
    char* temp_ptr = dataptrs[0];
    for (int i = 0; i < nargs; i++) {
        temp_ptr = dataptrs[i];
        dataptrs[i] = temp_ptr + subloopsize * strides[i];
    }
    dataptrs[0] = temp_ptr;
}
