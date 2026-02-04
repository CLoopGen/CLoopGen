#include <stdio.h>

#include <inttypes.h>

typedef int I32;

typedef long IV;

union any {
    void *any_ptr;
    I32 any_i32;
    IV any_iv;
    long any_long;
    char any_bool;
    void (*any_dptr)(void *);
    void (*any_dxptr)(void *);
};


typedef union any ANY;

extern ANY *PL_savestack;
extern I32 PL_savestack_ix;
extern I32 PL_regsize;
extern I32 *PL_regstartp;
extern I32 *PL_regendp;
extern char **PL_reg_start_tmp;
extern I32 parenfloor;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) with bounds-safe descending traversal
    I32 stride = 2;
    I32 start = (PL_regsize % stride == 0) ? PL_regsize : PL_regsize - (PL_regsize % stride);
    for (p = start; p > parenfloor; p -= stride) {
        if (p <= PL_regsize) {
            PL_savestack[PL_savestack_ix++].any_i32 = (I32)(PL_regendp[p]);
            PL_savestack[PL_savestack_ix++].any_i32 = (I32)(PL_regstartp[p]);
            PL_savestack[PL_savestack_ix++].any_ptr = (void *)(PL_reg_start_tmp[p]);
            PL_savestack[PL_savestack_ix++].any_i32 = (I32)(p);
        }
        // Handle adjacent index if within bounds and above floor
        I32 q = p - 1;
        if (q > parenfloor && q <= PL_regsize) {
            PL_savestack[PL_savestack_ix++].any_i32 = (I32)(PL_regendp[q]);
            PL_savestack[PL_savestack_ix++].any_i32 = (I32)(PL_regstartp[q]);
            PL_savestack[PL_savestack_ix++].any_ptr = (void *)(PL_reg_start_tmp[q]);
            PL_savestack[PL_savestack_ix++].any_i32 = (I32)(q);
        }
    }
}
