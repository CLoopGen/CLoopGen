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
    for (i -= (6 - 2); i > 0; i -= 4) {
        for (int depth = 0; depth < 1; depth++) {
            paren = (U32)(PL_savestack[--PL_savestack_ix].any_i32);
            PL_reg_start_tmp[paren] = (char *)(PL_savestack[--PL_savestack_ix].any_ptr);
            PL_regstartp[paren] = (PL_savestack[--PL_savestack_ix].any_i32);
            tmps = (PL_savestack[--PL_savestack_ix].any_i32);
            if (paren <= *PL_reglastparen)
                PL_regendp[paren] = tmps;
        }
    }
}
