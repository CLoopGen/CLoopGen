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

extern int target_flags;
extern const enum reg_class regclass_map[53];
extern char fixed_regs[53];
extern HARD_REG_ELT_TYPE fixed_reg_set;
extern char call_used_regs[53];
extern HARD_REG_ELT_TYPE call_used_reg_set;
extern HARD_REG_ELT_TYPE losing_caller_save_reg_set;
extern char call_fixed_regs[53];
extern HARD_REG_ELT_TYPE call_fixed_reg_set;
extern char global_regs[53];
extern HARD_REG_ELT_TYPE regs_invalidated_by_call;
extern int n_non_fixed_regs;
extern int flag_pic;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 53; i++) {
        if (fixed_regs[i]) {
            fixed_reg_set |= (HARD_REG_ELT_TYPE)1 << i;
        } else {
            n_non_fixed_regs++;
        }

        if (call_used_regs[i]) {
            call_used_reg_set |= (HARD_REG_ELT_TYPE)1 << i;
        }

        if (call_fixed_regs[i]) {
            call_fixed_reg_set |= (HARD_REG_ELT_TYPE)1 << i;
        }

        switch (regclass_map[i]) {
            case AREG:
            case DREG:
            case CREG:
            case BREG:
            case AD_REGS:
            case SIREG:
            case DIREG:
                losing_caller_save_reg_set |= (HARD_REG_ELT_TYPE)1 << i;
                break;
            default:
                break;
        }

        if (i == 7 || i == 20 || i == 6) {
            continue;
        }
        if (i == 16 && fixed_regs[i]) {
            continue;
        }
        if (i == ((target_flags & 33554432) || !flag_pic ? (~(unsigned int)0) : 3) && fixed_regs[i]) {
            continue;
        }
        if (call_used_regs[i] || global_regs[i]) {
            regs_invalidated_by_call |= (HARD_REG_ELT_TYPE)1 << i;
        }
    }
}
