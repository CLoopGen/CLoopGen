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
    int temp_is, temp_os;
    for (i = 0; i < x->rnk; ++i) {
        temp_is = x->dims[i].is;
        temp_os = x->dims[i].os;
        x->dims[i].is = temp_os;
        x->dims[i].os = temp_is;
    }
}
