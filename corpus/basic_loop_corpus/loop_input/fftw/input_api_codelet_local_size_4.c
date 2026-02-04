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

dtensor *sz;
ptrdiff_t *local_n;
ptrdiff_t *local_start;
int i;

void init_vars() {
    const int default_rank = 1000000; // Choose size to make loop take ~0.01s

    sz = (dtensor*)calloc(1, sizeof(dtensor) + (default_rank - 1) * sizeof(ddim));
    if (!sz) exit(1);
    sz->rnk = default_rank;

    local_n = (ptrdiff_t*)calloc(default_rank, sizeof(ptrdiff_t));
    if (!local_n) exit(1);

    local_start = (ptrdiff_t*)calloc(default_rank, sizeof(ptrdiff_t));
    if (!local_start) exit(1);
}