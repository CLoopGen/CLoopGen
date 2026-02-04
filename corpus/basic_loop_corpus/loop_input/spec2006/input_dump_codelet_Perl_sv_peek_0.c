#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned int U32;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};

typedef struct sv SV;

typedef int I32;

SV **PL_tmps_stack;
I32 PL_tmps_ix;
SV *sv;
int is_tmp;
I32 ix;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of input data
    PL_tmps_ix = (I32)(data_size - 1);
    PL_tmps_stack = malloc(data_size * sizeof(SV*));
    if (!PL_tmps_stack) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        PL_tmps_stack[i] = NULL;
    }

    sv = (SV*)malloc(sizeof(SV));
    if (!sv) {
        exit(1);
    }

    PL_tmps_stack[data_size / 2] = sv;

    is_tmp = 0;
    ix = 0;
}