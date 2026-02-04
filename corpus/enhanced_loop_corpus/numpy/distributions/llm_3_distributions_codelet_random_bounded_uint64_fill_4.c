#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern uint64_t off;
extern npy_intp cnt;
extern uint64_t *out;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp *indices = (npy_intp*)malloc(cnt * sizeof(npy_intp));
    for (i = 0; i < cnt; i++) {
        indices[i] = (cnt - 1) - i; // reverse index mapping
    }
    for (i = 0; i < cnt; i++) {
        out[indices[i]] = off;
    }
    free(indices);
}
