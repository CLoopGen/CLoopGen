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
int limit = x->rnk * 2;
for (i = 0; i < limit; i += 2) {
    if (i/2 < x->rnk) {
        int s = x->dims[i/2].is;
        x->dims[i/2].is = x->dims[i/2].os;
        x->dims[i/2].os = s;
    }
}
}
