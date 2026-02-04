#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef int I32;
typedef long IV;
typedef unsigned int U32;

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
extern I32 *PL_regstartp;
extern I32 *PL_regendp;
extern U32 *PL_reglastparen;
extern char **PL_reg_start_tmp;
extern I32 i;
extern U32 paren;
extern I32 tmps;

ANY *PL_savestack;
I32 PL_savestack_ix;
I32 *PL_regstartp;
I32 *PL_regendp;
U32 *PL_reglastparen;
char **PL_reg_start_tmp;
I32 i;
U32 paren;
I32 tmps;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    const int num_regs = 64;
    const int stack_depth = 256;

    PL_savestack = calloc(stack_depth, sizeof(ANY));
    if (!PL_savestack) exit(1);

    PL_regstartp = calloc(num_regs, sizeof(I32));
    PL_regendp = calloc(num_regs, sizeof(I32));
    PL_reg_start_tmp = calloc(num_regs, sizeof(char*));
    if (!PL_regstartp || !PL_regendp || !PL_reg_start_tmp) exit(1);

    for (int j = 0; j < num_regs; ++j) {
        PL_reg_start_tmp[j] = malloc(16);
        if (!PL_reg_start_tmp[j]) exit(1);
        sprintf(PL_reg_start_tmp[j], "tmp%d", j);
    }

    U32 reglastparen_storage = num_regs - 1;
    PL_reglastparen = &reglastparen_storage;

    // Initialize savestack with valid values
    int idx = 0;
    for (int j = 0; j < stack_depth / 4; ++j) {
        PL_savestack[idx].any_i32 = (U32)(num_regs - 1 - (j % num_regs));
        idx++;
        PL_savestack[idx].any_ptr = PL_reg_start_tmp[num_regs - 1 - (j % num_regs)];
        idx++;
        PL_savestack[idx].any_i32 = j * 100;
        idx++;
        PL_savestack[idx].any_i32 = j * 200;
        idx++;
    }

    PL_savestack_ix = stack_depth;
    i = stack_depth - (stack_depth % 4); // Ensure divisible by 4 to match loop step
}