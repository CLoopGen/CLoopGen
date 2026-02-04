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
    int stride = 1;
    for (i = 0; i < t->rnk; i += stride) {
        n[i] = t->dims[i].n;
        if (i + 1 < t->rnk) {
            n[i + 1] = t->dims[i + 1].n;
            stride = (t->dims[i].n > 4) ? 1 : 2;
        } else {
            stride = 1;
        }
    }
}
