#include <stdio.h>

#include <inttypes.h>

typedef unsigned int U32;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};


typedef struct sv SV;

typedef int I32;

extern SV **PL_tmps_stack;
extern I32 PL_tmps_ix;
extern SV *sv;
extern int is_tmp;
extern I32 ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 limit = PL_tmps_ix + 1;
    for (ix = 0; ix < limit; ix++) {
        I32 idx = PL_tmps_ix - ix;
        if (PL_tmps_stack[idx] == sv) {
            is_tmp = 1;
            break;
        }
    }
}
