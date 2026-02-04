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
    i = 0;

    sz = (dtensor*)malloc(sizeof(dtensor) + 4 * sizeof(ddim));
    if (!sz) exit(1);

    sz->rnk = 5;
    sz->dims[0].n = 10;
    sz->dims[1].n = 20;
    sz->dims[2].n = 30;
    sz->dims[3].n = 40;
    sz->dims[4].n = 50;

    for (int j = 0; j < sz->rnk; ++j) {
        sz->dims[j].b[0] = j * 2;
        sz->dims[j].b[1] = j * 2 + 1;
    }
}