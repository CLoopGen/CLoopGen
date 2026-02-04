#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef unsigned char npy_uint8;
typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;
typedef intptr_t Py_intptr_t;
typedef signed char npy_int8;

struct NpyIter_InternalOnly {
    int itflags;
    npy_uint8 ndim;
    int nop;
    int maskop;
    npy_intp itersize;
    npy_intp iterstart;
    npy_intp iterend;
    npy_intp iterindex;
    char iter_flexdata[];
};

typedef struct NpyIter_InternalOnly NpyIter;

struct NpyIter_AxisData_tag {
    npy_intp shape;
    npy_intp index;
    Py_intptr_t ad_flexdata;
};

typedef struct NpyIter_AxisData_tag NpyIter_AxisData;

NpyIter *iter;
int idim;
int ndim;
int iop;
int nop;
npy_intp istrides;
npy_intp nstrides;
NpyIter_AxisData *axisdata;
npy_intp *baseoffsets;
npy_intp sizeof_axisdata;
int any_flipped;

static char *temp_storage = NULL;

void init_vars(void) {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for workload

    ndim = 500;
    nop = 8;
    nstrides = nop;
    sizeof_axisdata = sizeof(NpyIter_AxisData);
    any_flipped = 0;

    size_t axisdata_size = ndim * sizeof_axisdata;
    size_t baseoffsets_size = nstrides * sizeof(npy_intp);
    size_t iter_flexdata_size = ndim * sizeof(npy_int8);

    size_t total_alloc = axisdata_size + baseoffsets_size + iter_flexdata_size + sizeof(NpyIter) + 256;

    temp_storage = (char *)calloc(1, total_alloc);
    if (!temp_storage) exit(1);

    char *ptr = temp_storage;

    iter = (NpyIter *)ptr;
    ptr += sizeof(NpyIter);
    iter->ndim = ndim;
    iter->nop = nop;
    iter->itersize = 0;
    iter->iterstart = 0;
    iter->iterend = 0;
    iter->iterindex = 0;
    memcpy(iter->iter_flexdata, ptr, iter_flexdata_size);
    ptr += iter_flexdata_size;

    axisdata = (NpyIter_AxisData *)ptr;
    ptr += axisdata_size;

    baseoffsets = (npy_intp *)ptr;
    ptr += baseoffsets_size;

    for (int i = 0; i < ndim; ++i) {
        axisdata[i].shape = (i % 97) + 1;
        axisdata[i].index = 0;
        npy_intp *strides = (npy_intp *)(&axisdata[i].ad_flexdata);
        for (int j = 0; j < nop; ++j) {
            strides[j] = ((i + j) % 5 == 0) ? -((i + 1) * 2) : ((i + j) % 3 == 0) ? ((i + 1)) : 0;
        }
        ((npy_int8 *)(iter->iter_flexdata))[i] = (npy_int8)(i % 127);
    }

    for (int j = 0; j < nstrides; ++j) {
        baseoffsets[j] = (j % 7) * 1000;
    }

    idim = 0;
    iop = 0;
    istrides = 0;
}