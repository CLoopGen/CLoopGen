#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

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


extern HARD_REG_ELT_TYPE reg_class_contents[25];
extern enum reg_class reg_class_superclasses[25][25];
extern enum reg_class reg_class_subclasses[25][25];
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use indirect indexing via a fixed offset array to simulate irregular memory access
    unsigned int index_map[25];
    for (unsigned int idx = 0; idx < LIM_REG_CLASSES; idx++) {
        index_map[idx] = idx;
    }

    for (i = 0; i < ((int)LIM_REG_CLASSES); i++) {
        if (i == (int)NO_REGS)
            continue;
        for (j = i + 1; j < ((int)LIM_REG_CLASSES); j++) {
            unsigned int super_idx = 0;
            unsigned int sub_idx = 0;

            // Indirect, consecutive scanning using indexed lookups instead of pointer chasing
            if (((HARD_REG_ELT_TYPE)(0)) == ((reg_class_contents[i]) & ~(reg_class_contents[j]))) {
                // Traverse reg_class_superclasses[i] indirectly
                for (super_idx = 0; super_idx < LIM_REG_CLASSES && reg_class_superclasses[i][super_idx] != LIM_REG_CLASSES; super_idx++);
                reg_class_superclasses[i][super_idx] = (enum reg_class)j;

                // Traverse reg_class_subclasses[j] indirectly
                for (sub_idx = 0; sub_idx < LIM_REG_CLASSES && reg_class_subclasses[j][sub_idx] != LIM_REG_CLASSES; sub_idx++);
                reg_class_subclasses[j][sub_idx] = (enum reg_class)i;
            }
        }
    }
}
