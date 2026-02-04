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

extern bench_tensor *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j;
for (i = 0; i < x->rnk; ++i) {
    for (j = 0; j < 1; ++j) { // Nested loop with depth increased by 1, inner loop runs once
        int s;
        s = x->dims[i].is;
        x->dims[i].is = x->dims[i].os;
        x->dims[i].os = s;
    }
}
}
