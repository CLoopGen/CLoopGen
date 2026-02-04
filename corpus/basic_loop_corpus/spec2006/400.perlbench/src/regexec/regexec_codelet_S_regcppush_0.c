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
for (p = PL_regsize; p > parenfloor; p--) {
    (PL_savestack[PL_savestack_ix++].any_i32 = (I32)(PL_regendp[p]));
    (PL_savestack[PL_savestack_ix++].any_i32 = (I32)(PL_regstartp[p]));
    (PL_savestack[PL_savestack_ix++].any_ptr = (void *)(PL_reg_start_tmp[p]));
    (PL_savestack[PL_savestack_ix++].any_i32 = (I32)(p));
}

}
