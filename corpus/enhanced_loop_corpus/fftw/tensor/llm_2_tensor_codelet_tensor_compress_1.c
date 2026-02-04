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
    bench_iodim *dims_ptr = sz->dims;
    bench_iodim *x_dims_ptr = x->dims;
    int sz_rnk = sz->rnk;

    for (i = rnk = 0; i < sz_rnk; ++i) {
        if ((dims_ptr + i)->n != 1) {
            *(x_dims_ptr + rnk++) = *(dims_ptr + i);
        }
    }
}
