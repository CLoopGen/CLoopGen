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
    int j;
    for (i = 0; i < t->rnk; ++i) {
        n[i] = t->dims[i].n * t->dims[i].is + t->dims[i].os;
        for (j = 1; j < t->dims[i].n; ++j) {
            n[i] += (t->dims[i].is - t->dims[i].os) / (j + 1);
        }
    }
}
