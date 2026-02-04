#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT b[2];
} ddim;

typedef struct {
    int rnk;
    ddim dims[1];
} dtensor;

int i;
dtensor *sz;
INT Nafter;

void init_vars() {
    Nafter = 1;
    sz = (dtensor*)malloc(offsetof(dtensor, dims) + 10 * sizeof(ddim));
    sz->rnk = 10;
    for (int j = 0; j < sz->rnk; ++j) {
        sz->dims[j].n = 3;
        sz->dims[j].b[0] = j;
        sz->dims[j].b[1] = j + 1;
    }
}
