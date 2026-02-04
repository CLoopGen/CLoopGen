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
INT n;

void init_vars() {
    n = 1;
    sz = (tensor*)malloc(sizeof(tensor) + 7 * sizeof(iodim));
    if (!sz) exit(1);
    sz->rnk = 8;
    for (int j = 0; j < 8; ++j) {
        sz->dims[j].n = 4;
        sz->dims[j].is = j * 2;
        sz->dims[j].os = j * 4;
    }
}

__attribute__((destructor))
static void cleanup() {
    free(sz);
}