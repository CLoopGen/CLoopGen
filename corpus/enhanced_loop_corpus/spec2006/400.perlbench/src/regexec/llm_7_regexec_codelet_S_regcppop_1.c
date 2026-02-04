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

typedef unsigned int U32;

extern ANY *PL_savestack;
extern I32 PL_savestack_ix;
extern I32 *PL_regstartp;
extern I32 *PL_regendp;
extern U32 *PL_reglastparen;
extern char **PL_reg_start_tmp;
extern I32 i;
extern U32 paren;
extern I32 tmps;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 local_stack_ix = PL_savestack_ix;
    I32 iteration_count = (i - 4 + 3) / 4; // Approximate number of iterations
    for (I32 step = 0; step < iteration_count && local_stack_ix >= 4; step++) {
        U32 local_paren = (U32)(PL_savestack[local_stack_ix - 1].any_i32);
        char* local_ptr = (char*)(PL_savestack[local_stack_ix - 2].any_ptr);
        I32 local_start = PL_savestack[local_stack_ix - 3].any_i32;
        I32 local_tmps = PL_savestack[local_stack_ix - 4].any_i32;
        local_stack_ix -= 4;

        PL_reg_start_tmp[local_paren] = local_ptr;
        PL_regstartp[local_paren] = local_start;
        if (local_paren <= *PL_reglastparen)
            PL_regendp[local_paren] = local_tmps;
    }
    PL_savestack_ix = local_stack_ix;
}
