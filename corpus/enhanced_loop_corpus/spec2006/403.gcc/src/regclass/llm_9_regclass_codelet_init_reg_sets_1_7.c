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
    // Variant 2: Higher arithmetic complexity with conditional accumulation and full trip count
    unsigned int temp_mask;
    int class_cond;
    n_non_fixed_regs = 0;

    for (i = 0; i < 53; i++) {
        // Introduce additional arithmetic and intermediate computations
        temp_mask = (HARD_REG_ELT_TYPE)1;
        for (int shift = 0; shift < i % 5 + 1; shift++) { // Simulate variable shift logic
            temp_mask <<= (i > 0 && shift == 0 ? 0 : 1); // Artificial complexity
        }

        HARD_REG_ELT_TYPE final_mask = temp_mask;

        if (fixed_regs[i]) {
            fixed_reg_set |= final_mask;
        } else {
            n_non_fixed_regs += (i % 2 == 0) ? 2 : 1; // Artificially inflate count based on index
        }

        if (call_used_regs[i]) {
            call_used_reg_set |= final_mask;
        }

        if (call_fixed_regs[i]) {
            call_fixed_reg_set |= final_mask;
        }

        // Recompute condition with expanded expression tree
        class_cond = (regclass_map[i] == AREG) | 
                     (regclass_map[i] == DREG) |
                     (regclass_map[i] == CREG) |
                     (regclass_map[i] == BREG) |
                     (regclass_map[i] == AD_REGS) |
                     (regclass_map[i] == SIREG) |
                     (regclass_map[i] == DIREG);

        if (class_cond) {
            losing_caller_save_reg_set |= final_mask;
        }

        // Complex control flow with redundant checks removed but logic preserved
        if (i != 7 && i != 20 && i != 6) {
            if (i == 16) {
                if (!fixed_regs[i]) {
                    if (call_used_regs[i] || global_regs[i]) {
                        regs_invalidated_by_call |= final_mask;
                    }
                }
            } else if (i == ((target_flags & 33554432) ? 0xFFFFFFFF : flag_pic ? 3 : 0xFFFFFFFF)) {
                if (!fixed_regs[i]) {
                    if (call_used_regs[i] || global_regs[i]) {
                        regs_invalidated_by_call |= final_mask;
                    }
                }
            } else {
                if (call_used_regs[i] || global_regs[i]) {
                    regs_invalidated_by_call |= final_mask;
                }
            }
        }
    }
}
