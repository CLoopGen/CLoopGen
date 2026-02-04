#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef signed char npy_int8;
typedef ssize_t Py_ssize_t;
typedef intptr_t Py_intptr_t;
typedef Py_ssize_t npy_intp;

struct NpyIter_AxisData_tag {
    npy_intp shape;
    npy_intp index;
    Py_intptr_t ad_flexdata;
};
typedef struct NpyIter_AxisData_tag NpyIter_AxisData;

int axis = 3;
int idim = 0;
int ndim = 8;
int iop = 0;
int nop = 4;
int xdim = 0;
npy_int8 *perm = NULL;
NpyIter_AxisData *axisdata_del = NULL;
npy_intp sizeof_axisdata = sizeof(NpyIter_AxisData);
npy_intp *baseoffsets = NULL;
char **resetdataptr = NULL;

static char *data_pool = NULL;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB for measurable runtime (~0.01 sec target)
    int i;

    // Allocate large pool for data pointers to avoid ASLR effects and ensure alignment
    data_pool = (char *)aligned_alloc(64, data_size);
    if (!data_pool) exit(1);
    memset(data_pool, 0, data_size);

    // Initialize perm: map dimensions with one negative match for axis
    perm = (npy_int8 *)malloc(ndim * sizeof(npy_int8));
    if (!perm) exit(1);
    for (i = 0; i < ndim; ++i) {
        perm[i] = (i == 5) ? (-1 - axis) : (npy_int8)(ndim - i);
    }

    // Allocate axisdata_del array
    axisdata_del = (NpyIter_AxisData *)aligned_alloc(64, ndim * sizeof_axisdata);
    if (!axisdata_del) exit(1);
    memset(axisdata_del, 0, ndim * sizeof_axisdata);
    for (i = 0; i < ndim; ++i) {
        axisdata_del[i].shape = (npy_intp)(1 + (i * 7) % 100); // reasonable shapes
        axisdata_del[i].index = 0;
        axisdata_del[i].ad_flexdata = 0;
    }

    // baseoffsets: one per operand
    baseoffsets = (npy_intp *)calloc(nop, sizeof(npy_intp));
    if (!baseoffsets) exit(1);

    // resetdataptr: char* per operand, point into data pool with spacing
    resetdataptr = (char **)malloc(nop * sizeof(char *));
    if (!resetdataptr) exit(1);
    for (i = 0; i < nop; ++i) {
        resetdataptr[i] = data_pool + (i * (data_size / nop)) + 1024;
    }
}