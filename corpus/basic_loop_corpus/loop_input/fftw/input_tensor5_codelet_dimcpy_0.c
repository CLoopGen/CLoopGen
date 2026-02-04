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

int rnk = 65536;
int i;

iodim *dst;
iodim *src;

void init_vars() {
    dst = (iodim*)aligned_alloc(64, rnk * sizeof(iodim));
    src = (iodim*)aligned_alloc(64, rnk * sizeof(iodim));

    for (int j = 0; j < rnk; ++j) {
        src[j].n = j * 4;
        src[j].is = j * 8 + 1;
        src[j].os = j * 16 + 2;
    }

    for (int j = 0; j < rnk; ++j) {
        dst[j].n = 0;
        dst[j].is = 0;
        dst[j].os = 0;
    }
}