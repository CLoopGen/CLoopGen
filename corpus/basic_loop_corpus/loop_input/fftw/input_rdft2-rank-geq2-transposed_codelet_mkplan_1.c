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

tensor *sz;
int i;
INT nrest;

void init_vars() {
    const int rank = 4;
    const INT dim0 = 16;
    const INT dim1 = 8;
    const INT dim2 = 8;
    const INT dim3 = 8;

    sz = (tensor*)calloc(1, sizeof(tensor) + (rank - 1) * sizeof(iodim));
    if (!sz) exit(1);

    sz->rnk = rank;
    sz->dims[0].n = dim0;
    sz->dims[0].is = 1;
    sz->dims[0].os = 1;
    sz->dims[1].n = dim1;
    sz->dims[1].is = 1;
    sz->dims[1].os = 1;
    sz->dims[2].n = dim2;
    sz->dims[2].is = 1;
    sz->dims[2].os = 1;
    sz->dims[3].n = dim3;
    sz->dims[3].is = 1;
    sz->dims[3].os = 1;

    nrest = 1;
    i = 1;
}