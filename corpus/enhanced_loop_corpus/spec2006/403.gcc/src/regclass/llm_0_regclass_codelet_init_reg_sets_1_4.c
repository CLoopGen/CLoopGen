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
extern enum reg_class reg_class_superunion[25][25];
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ((int)LIM_REG_CLASSES); i++) {
    for (j = 0; j < ((int)LIM_REG_CLASSES); j++) {
        register HARD_REG_ELT_TYPE c;
        int k, l;
        ((c) = (reg_class_contents[i]));
        ((c) |= (reg_class_contents[j]));
        for (k = 0; k < ((int)LIM_REG_CLASSES); k++) {
            if (((HARD_REG_ELT_TYPE)(0)) == ((c) & ~(reg_class_contents[k]))) {
                reg_class_superunion[i][j] = (enum reg_class)k;
                goto next_j;
            }
        }
        // Fallback in case no superclass found (should not happen with ALL_REGS)
        reg_class_superunion[i][j] = ALL_REGS;
      next_j: ;
    }
}
}
