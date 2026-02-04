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
    // Variant 1: Increased computational intensity with additional arithmetic and reduced trip count
    npy_intp step = (newnd - ni + 1) > 0 ? (newnd - ni + 1) / 2 : 0;
    for (nk = ni; nk < newnd; nk += 2) {
        newstrides[nk] = last_stride * 2 + (nk % 3);
        if (nk + step < newnd) {
            newstrides[nk + step] = last_stride * 3;
        }
    }
}
