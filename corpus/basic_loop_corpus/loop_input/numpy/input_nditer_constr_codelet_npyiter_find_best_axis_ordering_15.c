#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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

int idim;
int ndim = 4;
npy_int8 *perm;
NpyIter_AxisData *axisdata;
npy_intp sizeof_axisdata = sizeof(NpyIter_AxisData);
npy_intp i;
npy_intp size = 1024 * 256;  // ~1MB of index data (1024*256*sizeof(npy_intp) = 1MB if npy_intp is 8 bytes)
NpyIter_AxisData *ad_i;

void init_vars() {
    // Allocate and initialize perm: create a permutation of [0..ndim-1] with some cycles
    perm = (npy_int8*)malloc(ndim * sizeof(npy_int8));
    for (int j = 0; j < ndim; ++j) {
        perm[j] = (j + 1) % ndim;  // Circular shift: 0->1, 1->2, 2->3, 3->0
    }

    // Allocate axisdata as an array of ndim elements
    axisdata = (NpyIter_AxisData*)calloc(ndim, sizeof(NpyIter_AxisData));
    for (int j = 0; j < ndim; ++j) {
        axisdata[j].shape = size;
        axisdata[j].index = (j == 0 || j == 2) ? 1 : 0;  // Set index=1 for some axes to trigger logic
        axisdata[j].ad_flexdata = j;
    }

    // Ensure that the inner loop accesses within bounds:
    // The loop uses *((npy_intp *)ad_q + i) where i in [0, size)
    // So we need each axisdata element to be conceptually followed by 'size' npy_intp values.
    // But our current struct only has fixed layout. To make it safe, we must extend allocation.
    //
    // Instead, reinterpret: code treats `ad_q` as pointer to array of npy_intp with `size` extra slots.
    // So we reallocate axisdata as one large block: ndim * (sizeof(NpyIter_AxisData) + size * sizeof(npy_intp))
    // and align each ad_i to start at correct offset.

    free(axisdata);
    size_t total_size_per_axis = sizeof(NpyIter_AxisData) + size * sizeof(npy_intp);
    char *raw_mem = (char*)calloc(ndim, total_size_per_axis);

    axisdata = (NpyIter_AxisData*)raw_mem;

    for (int j = 0; j < ndim; ++j) {
        NpyIter_AxisData *ad = (NpyIter_AxisData*)(raw_mem + j * total_size_per_axis);
        ad->shape = size;
        ad->index = (j == 0 || j == 2) ? 1 : 0;
        ad->ad_flexdata = j;

        // Initialize the trailing npy_intp array for valid access
        npy_intp *extra = (npy_intp*)(ad + 1);
        for (npy_intp k = 0; k < size; ++k) {
            extra[k] = k ^ j;  // Arbitrary but defined pattern
        }
    }

    sizeof_axisdata = total_size_per_axis;  // Now each "axisdata" entry takes this much space
}