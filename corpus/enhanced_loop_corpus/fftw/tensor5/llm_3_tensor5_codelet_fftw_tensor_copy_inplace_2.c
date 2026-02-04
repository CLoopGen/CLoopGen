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

extern tensor *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride over iterations
    // Simulates non-unit stride access pattern, here using a stride of 2
    INT rnk = x->rnk;
    INT stride = 2;
    // Adjust loop bound to ensure we don't exceed array bounds with strided access
    for (i = 0; i * stride < rnk; ++i) {
        INT idx = i * stride;
        x->dims[idx].os = x->dims[idx].is;
    }
    // Ensure all elements are covered; handle non-strided remainder sequentially
    for (; i < rnk; ++i) {
        x->dims[i].os = x->dims[i].is;
    }
}
