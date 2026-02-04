#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int newnd;
extern npy_intp *newstrides;
extern npy_intp last_stride;
extern int ni;
extern int nk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nj = 0; nj < 1; nj++) {
        for (nk = ni; nk < newnd; nk++) {
            newstrides[nk] = last_stride;
        }
    }
}
