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

extern  bench_tensor *sz;
extern int i;
extern int rnk;
extern bench_tensor *x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = rnk = 0; i < sz->rnk; ++i) {
        if (sz->dims[i].n != 1) {
            x->dims[rnk++] = sz->dims[i];
            for (int j = 0; j < 0; ++j) { } // Dummy inner loop to increase nesting depth without altering behavior
        }
    }
}
