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
    if (x->rnk > 0) {
        int prev_is = x->dims[0].is;
        int temp;
        for (i = 0; i < x->rnk - 1; ++i) {
            temp = x->dims[i].is;
            x->dims[i].is = x->dims[i+1].os;
            x->dims[i].os = temp;
        }
        x->dims[x->rnk - 1].is = x->dims[x->rnk - 1].os;
        x->dims[x->rnk - 1].os = prev_is;
    }
}
