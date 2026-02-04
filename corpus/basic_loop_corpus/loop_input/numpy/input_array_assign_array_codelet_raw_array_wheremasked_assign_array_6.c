#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

int ndim = 4;
char *dst_data;
char *src_data;
char *wheremask_data;
int idim;
npy_intp shape_it[64];
npy_intp dst_strides_it[64];
npy_intp src_strides_it[64];
npy_intp wheremask_strides_it[64];
npy_intp coord[64];

static char *internal_dst_buffer;
static char *internal_src_buffer;
static char *internal_wheremask_buffer;

void init_vars() {
    const size_t total_elements = 1 << 20; // ~1M elements for reasonable timing (~0.01 sec)
    
    internal_dst_buffer = (char *)calloc(total_elements, sizeof(char));
    internal_src_buffer = (char *)calloc(total_elements, sizeof(char));
    internal_wheremask_buffer = (char *)calloc(total_elements, sizeof(char));

    if (!internal_dst_buffer || !internal_src_buffer || !internal_wheremask_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    dst_data = internal_dst_buffer;
    src_data = internal_src_buffer;
    wheremask_data = internal_wheremask_buffer;

    // Set dimensions: treat as 4D array roughly balanced in size
    ndim = 4;
    shape_it[0] = 1;
    shape_it[1] = 32;
    shape_it[2] = 32;
    shape_it[3] = 32;

    // Compute strides in C order (last dimension changes fastest)
    dst_strides_it[0] = 0;
    src_strides_it[0] = 0;
    wheremask_strides_it[0] = 0;

    npy_intp dst_stride = 1;
    npy_intp src_stride = 1;
    npy_intp wheremask_stride = 1;

    for (int i = ndim - 1; i >= 1; --i) {
        dst_strides_it[i] = dst_stride;
        src_strides_it[i] = src_stride;
        wheremask_strides_it[i] = wheremask_stride;
        dst_stride *= shape_it[i];
        src_stride *= shape_it[i];
        wheremask_stride *= shape_it[i];
    }

    // Initialize coordinates to zero
    for (int i = 0; i < ndim; ++i) {
        coord[i] = 0;
    }
    idim = 0;

    // Ensure initial pointers are at start
    dst_data = internal_dst_buffer;
    src_data = internal_src_buffer;
    wheremask_data = internal_wheremask_buffer;
}