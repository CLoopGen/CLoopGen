#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef signed char npy_int8;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef intptr_t Py_intptr_t;

struct NpyIter_AxisData_tag {
    npy_intp shape;
    npy_intp index;
    Py_intptr_t ad_flexdata;
};


typedef struct NpyIter_AxisData_tag NpyIter_AxisData;

extern int axis;
extern int idim;
extern int ndim;
extern int iop;
extern int nop;
extern int xdim;
extern npy_int8 *perm;
extern NpyIter_AxisData *axisdata_del;
extern npy_intp sizeof_axisdata;
extern npy_intp *baseoffsets;
extern char **resetdataptr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Indirect memory access via an index map to simulate irregular access pattern
    npy_intp index_map[32]; // Assume max ndim is 32
    for (idim = 0; idim < ndim; ++idim) {
        index_map[idim] = idim; // Identity map, could be randomized in real use cases
    }

    for (idim = 0; idim < ndim; ++idim) {
        int mapped_idim = (int)index_map[idim]; // Indirect access to loop index
        npy_int8 p = perm[mapped_idim];

        if (p == axis) {
            xdim = mapped_idim;
            break;
        } else if (-1 - p == axis) {
            NpyIter_AxisData *current_axis = (NpyIter_AxisData *)(((char *)axisdata_del) + mapped_idim * sizeof_axisdata);
            npy_intp *strides = &(current_axis->ad_flexdata);
            npy_intp shape = current_axis->shape;
            npy_intp offset;
            xdim = mapped_idim;

            // Indirect operand access using a precomputed operand index map
            npy_intp op_index_map[16]; // Assume max nop is 16
            for (iop = 0; iop < nop; ++iop) {
                op_index_map[iop] = iop; // Could be shuffled or reordered
            }

            for (iop = 0; iop < nop; ++iop) {
                int actual_iop = (int)op_index_map[iop]; // Indirect operand indexing
                offset = (shape - 1) * strides[actual_iop];
                baseoffsets[actual_iop] += offset;
                resetdataptr[actual_iop] += offset;
            }
            break;
        }
    }
}
