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
    // Variant 1: Consecutive memory access with loop unrolling and array base pointer arithmetic
    HARD_REG_ELT_TYPE *fr_set = &fixed_reg_set;
    HARD_REG_ELT_TYPE *cu_set = &call_used_reg_set;
    HARD_REG_ELT_TYPE *cf_set = &call_fixed_reg_set;
    HARD_REG_ELT_TYPE *lose_set = &losing_caller_save_reg_set;
    HARD_REG_ELT_TYPE *invalidate_set = &regs_invalidated_by_call;

    const enum reg_class *rc_map = regclass_map;
    const char *fr_regs = fixed_regs;
    const char *cu_regs = call_used_regs;
    const char *cf_regs = call_fixed_regs;
    const char *gl_regs = global_regs;

    // Unroll by 4 to improve spatial locality and reduce branch overhead
    for (i = 0; i < 52; i += 4) {
        // Process i
        if (fr_regs[i])
            (*fr_set) |= (HARD_REG_ELT_TYPE)1 << i;
        else
            n_non_fixed_regs++;
        if (cu_regs[i])
            (*cu_set) |= (HARD_REG_ELT_TYPE)1 << i;
        if (cf_regs[i])
            (*cf_set) |= (HARD_REG_ELT_TYPE)1 << i;
        if ((rc_map[i] == AREG) || (rc_map[i] == DREG) || (rc_map[i] == CREG) ||
            (rc_map[i] == BREG) || (rc_map[i] == AD_REGS) || (rc_map[i] == SIREG) || (rc_map[i] == DIREG))
            (*lose_set) |= (HARD_REG_ELT_TYPE)1 << i;
        if (!(i == 7 || i == 20) && !(i == 6) && !(i == 16 && fr_regs[i]) &&
            !(i == ((target_flags & 33554432) || !flag_pic ? (~(unsigned int)0) : 3) && fr_regs[i]))
            if (0 || cu_regs[i] || gl_regs[i])
                (*invalidate_set) |= (HARD_REG_ELT_TYPE)1 << i;

        // Process i+1
        if (fr_regs[i+1])
            (*fr_set) |= (HARD_REG_ELT_TYPE)1 << (i+1);
        else
            n_non_fixed_regs++;
        if (cu_regs[i+1])
            (*cu_set) |= (HARD_REG_ELT_TYPE)1 << (i+1);
        if (cf_regs[i+1])
            (*cf_set) |= (HARD_REG_ELT_TYPE)1 << (i+1);
        if ((rc_map[i+1] == AREG) || (rc_map[i+1] == DREG) || (rc_map[i+1] == CREG) ||
            (rc_map[i+1] == BREG) || (rc_map[i+1] == AD_REGS) || (rc_map[i+1] == SIREG) || (rc_map[i+1] == DIREG))
            (*lose_set) |= (HARD_REG_ELT_TYPE)1 << (i+1);
        if (!((i+1) == 7 || (i+1) == 20) && !((i+1) == 6) && !((i+1) == 16 && fr_regs[i+1]) &&
            !((i+1) == ((target_flags & 33554432) || !flag_pic ? (~(unsigned int)0) : 3) && fr_regs[i+1]))
            if (0 || cu_regs[i+1] || gl_regs[i+1])
                (*invalidate_set) |= (HARD_REG_ELT_TYPE)1 << (i+1);

        // Process i+2
        if (fr_regs[i+2])
            (*fr_set) |= (HARD_REG_ELT_TYPE)1 << (i+2);
        else
            n_non_fixed_regs++;
        if (cu_regs[i+2])
            (*cu_set) |= (HARD_REG_ELT_TYPE)1 << (i+2);
        if (cf_regs[i+2])
            (*cf_set) |= (HARD_REG_ELT_TYPE)1 << (i+2);
        if ((rc_map[i+2] == AREG) || (rc_map[i+2] == DREG) || (rc_map[i+2] == CREG) ||
            (rc_map[i+2] == BREG) || (rc_map[i+2] == AD_REGS) || (rc_map[i+2] == SIREG) || (rc_map[i+2] == DIREG))
            (*lose_set) |= (HARD_REG_ELT_TYPE)1 << (i+2);
        if (!((i+2) == 7 || (i+2) == 20) && !((i+2) == 6) && !((i+2) == 16 && fr_regs[i+2]) &&
            !((i+2) == ((target_flags & 33554432) || !flag_pic ? (~(unsigned int)0) : 3) && fr_regs[i+2]))
            if (0 || cu_regs[i+2] || gl_regs[i+2])
                (*invalidate_set) |= (HARD_REG_ELT_TYPE)1 << (i+2);

        // Process i+3
        if (fr_regs[i+3])
            (*fr_set) |= (HARD_REG_ELT_TYPE)1 << (i+3);
        else
            n_non_fixed_regs++;
        if (cu_regs[i+3])
            (*cu_set) |= (HARD_REG_ELT_TYPE)1 << (i+3);
        if (cf_regs[i+3])
            (*cf_set) |= (HARD_REG_ELT_TYPE)1 << (i+3);
        if ((rc_map[i+3] == AREG) || (rc_map[i+3] == DREG) || (rc_map[i+3] == CREG) ||
            (rc_map[i+3] == BREG) || (rc_map[i+3] == AD_REGS) || (rc_map[i+3] == SIREG) || (rc_map[i+3] == DIREG))
            (*lose_set) |= (HARD_REG_ELT_TYPE)1 << (i+3);
        if (!((i+3) == 7 || (i+3) == 20) && !((i+3) == 6) && !((i+3) == 16 && fr_regs[i+3]) &&
            !((i+3) == ((target_flags & 33554432) || !flag_pic ? (~(unsigned int)0) : 3) && fr_regs[i+3]))
            if (0 || cu_regs[i+3] || gl_regs[i+3])
                (*invalidate_set) |= (HARD_REG_ELT_TYPE)1 << (i+3);
    }
    // Handle remainder
    for (; i < 53; i++) {
        if (fixed_regs[i])
            ((fixed_reg_set) |= ((HARD_REG_ELT_TYPE)(1)) << (i));
        else
            n_non_fixed_regs++;
        if (call_used_regs[i])
            ((call_used_reg_set) |= ((HARD_REG_ELT_TYPE)(1)) << (i));
        if (call_fixed_regs[i])
            ((call_fixed_reg_set) |= ((HARD_REG_ELT_TYPE)(1)) << (i));
        if (((((regclass_map[i])) == AREG) || (((regclass_map[i])) == DREG) || (((regclass_map[i])) == CREG) || (((regclass_map[i])) == BREG) || (((regclass_map[i])) == AD_REGS) || (((regclass_map[i])) == SIREG) || (((regclass_map[i])) == DIREG)))
            ((losing_caller_save_reg_set) |= ((HARD_REG_ELT_TYPE)(1)) << (i));
        if (i == 7 || i == 20)
            ;
        else if (i == 6)
            ;
        else if (i == 16 && fixed_regs[i])
            ;
        else if (i == ((target_flags & 33554432) || !flag_pic ? (~(unsigned int)0) : 3) && fixed_regs[i])
            ;
        else if (0 || call_used_regs[i] || global_regs[i])
            ((regs_invalidated_by_call) |= ((HARD_REG_ELT_TYPE)(1)) << (i));
    }
}
