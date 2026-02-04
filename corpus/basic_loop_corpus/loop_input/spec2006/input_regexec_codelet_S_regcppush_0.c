#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

I32 PL_regsize = 100000;
I32 parenfloor = 0;
int p;

ANY *PL_savestack;
I32 PL_savestack_ix;

I32 *PL_regstartp;
I32 *PL_regendp;
char **PL_reg_start_tmp;

void init_vars() {
    const size_t data_size = 100000; // ~1.6MB of data, adjust for ~0.01s runtime

    PL_savestack = (ANY *)calloc(data_size * 4, sizeof(ANY));
    PL_regstartp = (I32 *)calloc(data_size, sizeof(I32));
    PL_regendp = (I32 *)calloc(data_size, sizeof(I32));
    PL_reg_start_tmp = (char **)calloc(data_size, sizeof(char *));

    for (size_t i = 0; i < data_size; i++) {
        PL_regstartp[i] = i * 2;
        PL_regendp[i] = i * 3;
        PL_reg_start_tmp[i] = (char *)&PL_regstartp[i];
    }

    PL_savestack_ix = 0;
}