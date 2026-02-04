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

tensor *x;
int i;

void init_vars() {
    const int rank = 1000000;
    x = (tensor*)calloc(1, sizeof(tensor) + (rank - 1) * sizeof(iodim));
    x->rnk = rank;
    for (int j = 0; j < rank; ++j) {
        x->dims[j].n = j;
        x->dims[j].is = 0;
        x->dims[j].os = j * 2;
    }
    i = 0;
}