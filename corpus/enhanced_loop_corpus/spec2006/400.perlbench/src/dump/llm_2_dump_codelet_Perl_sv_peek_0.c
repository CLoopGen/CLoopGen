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
    // Variant 1: Consecutive memory access with forward traversal (unrolled by 2 for consecutive pattern)
    is_tmp = 0;
    I32 start = PL_tmps_ix & ~1;  // Round down to nearest even index
    for (ix = start; ix >= 0; ix -= 2) {
        if (PL_tmps_stack[ix] == sv) {
            is_tmp = 1;
            break;
        }
        if (ix - 1 >= 0 && PL_tmps_stack[ix - 1] == sv) {
            is_tmp = 1;
            break;
        }
    }
    // Handle odd starting index if needed
    if (!is_tmp && (PL_tmps_ix & 1)) {
        if (PL_tmps_stack[PL_tmps_ix] == sv) {
            is_tmp = 1;
        }
    }
}
