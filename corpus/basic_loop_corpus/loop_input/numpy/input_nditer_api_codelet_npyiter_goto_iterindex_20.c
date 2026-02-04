#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef intptr_t Py_intptr_t;
typedef Py_ssize_t npy_intp;

struct NpyIter_AxisData_tag {
    npy_intp shape;
    npy_intp index;
    Py_intptr_t ad_flexdata;
};
typedef struct NpyIter_AxisData_tag NpyIter_AxisData;

npy_intp iterindex;
int idim;
int ndim;
char **dataptrs;
NpyIter_AxisData *axisdata;
npy_intp sizeof_axisdata;
npy_intp istrides;
npy_intp nstrides;
npy_intp i;
npy_intp shape;

#define DATA_SIZE (64 * 1024 * 1024)
#define NUM_STRIDES 8
#define MAX_DIMS 32

static char *data_buffer;
static npy_intp *strides_buffer;
static NpyIter_AxisData axisdata_buffer[MAX_DIMS];

void init_vars() {
    data_buffer = (char *)calloc(DATA_SIZE, 1);
    dataptrs = (char **)calloc(NUM_STRIDES, sizeof(char *));
    strides_buffer = (npy_intp *)calloc(MAX_DIMS * NUM_STRIDES, sizeof(npy_intp));

    ndim = 5;
    nstrides = NUM_STRIDES;
    sizeof_axisdata = sizeof(NpyIter_AxisData);
    iterindex = 100000;

    for (int i = 0; i < NUM_STRIDES; ++i) {
        dataptrs[i] = data_buffer + (i * 65536);
    }

    for (int dim = 0; dim < ndim; ++dim) {
        NpyIter_AxisData *ad = &axisdata_buffer[dim];
        ad->shape = (dim + 2) * 100;
        ad->index = 0;
        npy_intp *strides = (npy_intp *)&ad->ad_flexdata;
        for (int s = 0; s < NUM_STRIDES; ++s) {
            strides[s] = (s + 1) * 1000;
        }
    }

    axisdata = axisdata_buffer;
}