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
int i = 0;
if (x != NULL && x->dims != NULL) {
    for (; i < x->rnk; ++i) {
        int s = x->dims[i].is;
        x->dims[i].is = x->dims[i].os;
        x->dims[i].os = s;
    }
}
}
