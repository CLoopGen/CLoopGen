#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT is;
    INT os;
} iodim;

typedef struct {
    int rnk;
    iodim dims[1];
} tensor;

extern int rnk;
extern  int *n;
extern  int *niphys;
extern  int *nophys;
extern tensor *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Introduce stride simulation by accessing every second element in reverse, then filling gaps
    iodim *d = x->dims;
    INT step = 2;

    // First pass: process elements with strided access (every 'step'-th element)
    for (i = rnk - 1; i > 0; i -= step) {
        if (i - step >= 0) {
            d[i - step].is = d[i].is * niphys[i];
            d[i - step].os = d[i].os * nophys[i];
            d[i - step].n = n[i - step];
        }
    }

    // Second pass: fill in the skipped elements with unit stride
    for (i = rnk - 1; i > 0; --i) {
        if (x->dims[i].is == 0 && i + 1 < rnk) { // assume zero-init gap
            x->dims[i - 1].is = x->dims[i].is * niphys[i];
        }
        if (x->dims[i].os == 0 && i + 1 < rnk) {
            x->dims[i - 1].os = x->dims[i].os * nophys[i];
        }
        x->dims[i - 1].n = n[i - 1]; // always defined
    }
}
