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
    const int rank = 5;
    sz = (tensor*)malloc(sizeof(tensor) + (rank - 1) * sizeof(iodim));
    sz->rnk = rank;
    sz->dims[0].n = 10;
    sz->dims[0].is = 1;
    sz->dims[0].os = 8;
    sz->dims[1].n = 20;
    sz->dims[1].is = 2;
    sz->dims[1].os = 16;
    sz->dims[2].n = 30;
    sz->dims[2].is = 3;
    sz->dims[2].os = 24;
    sz->dims[3].n = 40;
    sz->dims[3].is = 4;
    sz->dims[3].os = 32;
    sz->dims[4].n = 50;
    sz->dims[4].is = 5;
    sz->dims[4].os = 40;
    i = 0;
    nrest = 1;
}