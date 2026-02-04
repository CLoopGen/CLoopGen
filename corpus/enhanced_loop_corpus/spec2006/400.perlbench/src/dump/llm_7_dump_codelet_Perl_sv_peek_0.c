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
    I32 local_ix = PL_tmps_ix;
    for (ix = 0; ix <= local_ix; ix++) {
        if (PL_tmps_stack[local_ix - ix] == sv) {
            is_tmp = 1;
            break;
        }
    }
}
