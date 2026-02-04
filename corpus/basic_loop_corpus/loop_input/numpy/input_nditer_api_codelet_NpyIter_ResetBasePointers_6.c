#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int iop;
int nop = 1000000; // 1M iterations to target ~0.01 sec runtime

char **baseptrs;
char **resetdataptr;
npy_intp *baseoffsets;

void init_vars() {
    nop = 1000000;
    
    baseptrs = (char**)calloc(nop, sizeof(char*));
    resetdataptr = (char**)calloc(nop, sizeof(char*));
    baseoffsets = (npy_intp*)malloc(nop * sizeof(npy_intp));
    
    for (int i = 0; i < nop; ++i) {
        baseptrs[i] = (char*)malloc(8); // Small buffers
        baseoffsets[i] = 4; // Offset within allocated block
    }
}