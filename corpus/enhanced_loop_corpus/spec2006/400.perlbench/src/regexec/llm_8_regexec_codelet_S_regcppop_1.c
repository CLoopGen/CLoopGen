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
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    for (i -= 8; i > 0; i -= 8) {
        U32 paren1, paren2;
        char *tmp_ptr1, *tmp_ptr2;
        I32 tmps1, tmps2;

        // First iteration of unrolled pair
        paren1 = (U32)(PL_savestack[--PL_savestack_ix].any_i32);
        tmp_ptr1 = (char *)(PL_savestack[--PL_savestack_ix].any_ptr);
        PL_regstartp[paren1] = (PL_savestack[--PL_savestack_ix].any_i32);
        tmps1 = (PL_savestack[--PL_savestack_ix].any_i32);
        if (paren1 <= *PL_reglastparen)
            PL_regendp[paren1] = tmps1;
        PL_reg_start_tmp[paren1] = tmp_ptr1;

        // Second iteration of unrolled pair (if enough elements)
        if (i > 4) {
            paren2 = (U32)(PL_savestack[--PL_savestack_ix].any_i32);
            tmp_ptr2 = (char *)(PL_savestack[--PL_savestack_ix].any_ptr);
            PL_regstartp[paren2] = (PL_savestack[--PL_savestack_ix].any_i32);
            tmps2 = (PL_savestack[--PL_savestack_ix].any_i32);
            if (paren2 <= *PL_reglastparen)
                PL_regendp[paren2] = tmps2;
            PL_reg_start_tmp[paren2] = tmp_ptr2;
        }
    }
}
