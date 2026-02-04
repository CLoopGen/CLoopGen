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
    int prev = 1;
    for (i = 0; i < t->rnk; ++i) {
        n[i] = t->dims[i].n * prev;
        prev = n[i];
    }
}
