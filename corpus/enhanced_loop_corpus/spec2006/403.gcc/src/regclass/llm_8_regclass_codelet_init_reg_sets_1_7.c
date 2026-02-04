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
    // Variant 1: Increased computational intensity with unrolled inner operations and reduced trip count
    n_non_fixed_regs = 0;
    for (i = 0; i < 53; i += 4) {
        // Process 4 elements per iteration to reduce loop overhead
        int indices[4] = {i, i+1, i+2, i+3};
        for (int j = 0; j < 4; j++) {
            if (indices[j] >= 53) break;

            int idx = indices[j];
            HARD_REG_ELT_TYPE mask = ((HARD_REG_ELT_TYPE)1) << idx;

            if (fixed_regs[idx]) {
                fixed_reg_set |= mask;
            } else {
                n_non_fixed_regs++;
            }

            if (call_used_regs[idx]) {
                call_used_reg_set |= mask;
            }

            if (call_fixed_regs[idx]) {
                call_fixed_reg_set |= mask;
            }

            enum reg_class rc = regclass_map[idx];
            if (rc == AREG || rc == DREG || rc == CREG || rc == BREG ||
                rc == AD_REGS || rc == SIREG || rc == DIREG) {
                losing_caller_save_reg_set |= mask;
            }

            if (!(idx == 7 || idx == 20 || idx == 6 || 
                  (idx == 16 && fixed_regs[idx]) ||
                  (idx == ((target_flags & 33554432) || !flag_pic ? (~(unsigned int)0) : 3) && fixed_regs[idx]))) {
                if (call_used_regs[idx] || global_regs[idx]) {
                    regs_invalidated_by_call |= mask;
                }
            }
        }
    }
}
