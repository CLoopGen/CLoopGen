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
    // Variant 1: Consecutive memory access with reversed iteration using pointer arithmetic
    I32 *regend = PL_regendp + PL_regsize;
    I32 *regstart = PL_regstartp + PL_regsize;
    char **regtmp = PL_reg_start_tmp + PL_regsize;
    for (p = PL_regsize; p > parenfloor; p--) {
        PL_savestack[PL_savestack_ix++].any_i32 = (I32)(*(--regend));
        PL_savestack[PL_savestack_ix++].any_i32 = (I32)(*(--regstart));
        PL_savestack[PL_savestack_ix++].any_ptr = (void *)(*(--regtmp));
        PL_savestack[PL_savestack_ix++].any_i32 = (I32)(p);
    }
}
