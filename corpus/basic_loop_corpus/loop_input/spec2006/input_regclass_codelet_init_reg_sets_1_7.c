#include <stdio.h>
#include <inttypes.h>

enum reg_class {
    NO_REGS,
    AREG,
    DREG,
    CREG,
    BREG,
    SIREG,
    DIREG,
    AD_REGS,
    Q_REGS,
    NON_Q_REGS,
    INDEX_REGS,
    LEGACY_REGS,
    GENERAL_REGS,
    FP_TOP_REG,
    FP_SECOND_REG,
    FLOAT_REGS,
    SSE_REGS,
    MMX_REGS,
    FP_TOP_SSE_REGS,
    FP_SECOND_SSE_REGS,
    FLOAT_SSE_REGS,
    FLOAT_INT_REGS,
    INT_SSE_REGS,
    FLOAT_INT_SSE_REGS,
    ALL_REGS,
    LIM_REG_CLASSES
};

typedef unsigned long HARD_REG_ELT_TYPE;

int target_flags;
const enum reg_class regclass_map[53] = {
    NO_REGS, AREG, DREG, CREG, BREG, SIREG, DIREG, AD_REGS,
    Q_REGS, NON_Q_REGS, INDEX_REGS, LEGACY_REGS, GENERAL_REGS,
    FP_TOP_REG, FP_SECOND_REG, FLOAT_REGS, SSE_REGS, MMX_REGS,
    FP_TOP_SSE_REGS, FP_SECOND_SSE_REGS, FLOAT_SSE_REGS, FLOAT_INT_REGS,
    INT_SSE_REGS, FLOAT_INT_SSE_REGS, ALL_REGS, NO_REGS, AREG, DREG,
    CREG, BREG, SIREG, DIREG, AD_REGS, Q_REGS, NON_Q_REGS, INDEX_REGS,
    LEGACY_REGS, GENERAL_REGS, FP_TOP_REG, FP_SECOND_REG, FLOAT_REGS,
    SSE_REGS, MMX_REGS, FP_TOP_SSE_REGS, FP_SECOND_SSE_REGS, FLOAT_SSE_REGS,
    FLOAT_INT_REGS, INT_SSE_REGS, FLOAT_INT_SSE_REGS, ALL_REGS, NO_REGS,
    AREG, DREG, CREG, BREG
};
char fixed_regs[53];
HARD_REG_ELT_TYPE fixed_reg_set;
char call_used_regs[53];
HARD_REG_ELT_TYPE call_used_reg_set;
HARD_REG_ELT_TYPE losing_caller_save_reg_set;
char call_fixed_regs[53];
HARD_REG_ELT_TYPE call_fixed_reg_set;
char global_regs[53];
HARD_REG_ELT_TYPE regs_invalidated_by_call;
int n_non_fixed_regs;
int flag_pic;
unsigned int i;

void init_vars() {
    target_flags = 33554432;
    flag_pic = 0;
    n_non_fixed_regs = 0;

    for (i = 0; i < 53; i++) {
        fixed_regs[i] = (i % 7 == 0) ? 1 : 0;
        call_used_regs[i] = (i % 5 == 0) ? 1 : 0;
        call_fixed_regs[i] = (i % 13 == 0) ? 1 : 0;
        global_regs[i] = (i % 17 == 0) ? 1 : 0;
    }

    fixed_reg_set = 0;
    call_used_reg_set = 0;
    call_fixed_reg_set = 0;
    losing_caller_save_reg_set = 0;
    regs_invalidated_by_call = 0;
}