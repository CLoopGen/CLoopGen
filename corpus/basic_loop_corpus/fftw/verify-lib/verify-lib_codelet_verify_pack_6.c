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
for (i = x->rnk - 1; i > 0; --i) {
    x->dims[i - 1].is = x->dims[i].is * x->dims[i].n;
    x->dims[i - 1].os = x->dims[i].os * x->dims[i].n;
}

}
