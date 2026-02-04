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

static SV **src_array;
static SV **dst_array;
SV **src;
SV **dst;
I32 i;
I32 after;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: ~1M pointers
    after = data_size;

    src_array = malloc(after * sizeof(SV*));
    dst_array = malloc(after * sizeof(SV*));

    for (size_t idx = 0; idx < after; ++idx) {
        SV* sv = malloc(sizeof(SV));
        sv->sv_any = NULL;
        sv->sv_refcnt = idx;
        sv->sv_flags = idx ^ 0xdeadbeef;
        src_array[idx] = sv;
    }

    src = &src_array[after - 1];
    dst = &dst_array[after - 1];
}