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

tensor *sz;
int i;
int rnk;

static tensor *allocated_tensor;
static const int fixed_rnk = 200000;

void init_vars() {
    size_t total_size = sizeof(tensor) + (fixed_rnk - 1) * sizeof(iodim);
    allocated_tensor = (tensor*)calloc(1, total_size);
    if (!allocated_tensor) {
        exit(1);
    }
    allocated_tensor->rnk = fixed_rnk;
    
    for (int idx = 0; idx < fixed_rnk; ++idx) {
        allocated_tensor->dims[idx].n = (idx % 7 == 0) ? 1 : 2;
        allocated_tensor->dims[idx].is = idx * 2;
        allocated_tensor->dims[idx].os = idx * 4;
    }

    sz = allocated_tensor;
    i = 0;
    rnk = 0;
}