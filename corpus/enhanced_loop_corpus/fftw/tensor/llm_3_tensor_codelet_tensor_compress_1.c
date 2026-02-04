#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int n;
    int is;
    int os;
} bench_iodim;

typedef struct {
    int rnk;
    bench_iodim *dims;
} bench_tensor;

extern  bench_tensor *sz;
extern int i;
extern int rnk;
extern bench_tensor *x;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int i, rnk;
    bench_iodim *dims_base = sz->dims;
    bench_iodim *x_dims_base = x->dims;
    int *n_array = (int*)malloc(sz->rnk * sizeof(int));
    int *index_map = (int*)malloc(sz->rnk * sizeof(int));
    
    // Precompute indices and values for indirect access pattern
    for (i = 0; i < sz->rnk; ++i) {
        n_array[i] = dims_base[i].n;
        index_map[i] = i;
    }

    for (i = rnk = 0; i < sz->rnk; ++i) {
        int idx = index_map[i]; // Indirect access via index map
        if (n_array[idx] != 1) {
            x_dims_base[rnk++] = dims_base[idx];
        }
    }

    free(n_array);
    free(index_map);
}
