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

extern bench_tensor *t;
extern int *n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *local_n = n;
    bench_iodim *dims = t->dims;
    int rnk = t->rnk;
    for (int i = 0; i < rnk; ++i) {
        local_n[i] = dims[i].n;
    }
}
