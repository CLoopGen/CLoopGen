#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT is;
    INT os;
} iodim;

typedef struct {
    int rnk;
    iodim dims[1];
} tensor;

// Define external variables
int i;
int rnk;
tensor *sz;
tensor *x;

// Forward declaration for init_vars
void init_vars(void);

void init_vars() {
    // Set rank and allocate sz with sufficient size to ensure meaningful runtime (~0.01 sec)
    const int num_dims = 256 * 1024; // Large number of dimensions to create non-trivial loop overhead

    // Allocate sz
    size_t sz_size = sizeof(tensor) + (num_dims - 1) * sizeof(iodim);
    sz = (tensor *)malloc(sz_size);
    if (!sz) {
        exit(1);
    }
    sz->rnk = num_dims;

    // Initialize sz->dims: most have n != 1 so they will be copied
    for (int idx = 0; idx < num_dims; ++idx) {
        sz->dims[idx].n = (idx % 7 == 0) ? 1 : (idx % 13 + 2); // Some n==1, others not
        sz->dims[idx].is = idx * 2;
        sz->dims[idx].os = idx * 4;
    }

    // Allocate x with maximum possible size (in case all dims are copied)
    size_t x_size = sizeof(tensor) + (num_dims - 1) * sizeof(iodim);
    x = (tensor *)malloc(x_size);
    if (!x) {
        free(sz);
        exit(1);
    }
    x->rnk = 0; // Will be incremented in loop
}