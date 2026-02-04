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

INT ishift;
INT oshift;
tensor *cld_vec;
int i;

static tensor *alloc_tensor(int rank) {
    size_t size = sizeof(tensor) + (rank - 1) * sizeof(iodim);
    tensor *t = (tensor*)calloc(1, size);
    t->rnk = rank;
    return t;
}

void init_vars() {
    ishift = 1000000;
    oshift = 2000000;
    i = 0;

    int rank = 5;
    cld_vec = alloc_tensor(rank);
    cld_vec->rnk = rank;

    cld_vec->dims[0].n = 1000;
    cld_vec->dims[0].is = -2;
    cld_vec->dims[0].os = -3;

    cld_vec->dims[1].n = 500;
    cld_vec->dims[1].is = 4;
    cld_vec->dims[1].os = -5;

    cld_vec->dims[2].n = 800;
    cld_vec->dims[2].is = -6;
    cld_vec->dims[2].os = 7;

    cld_vec->dims[3].n = 300;
    cld_vec->dims[3].is = -8;
    cld_vec->dims[3].os = -9;

    cld_vec->dims[4].n = 1200;
    cld_vec->dims[4].is = 10;
    cld_vec->dims[4].os = -11;
}