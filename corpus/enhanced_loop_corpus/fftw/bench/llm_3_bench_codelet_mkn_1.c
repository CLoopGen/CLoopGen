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
    int rnk = t->rnk;
    bench_iodim *dims = t->dims;
    int *local_n = n;
    for (int i = 0; i < rnk; i += 2) {
        local_n[i] = dims[i].n;
        if (i + 1 < rnk) {
            local_n[i + 1] = dims[i + 1].n;
        }
    }
}
