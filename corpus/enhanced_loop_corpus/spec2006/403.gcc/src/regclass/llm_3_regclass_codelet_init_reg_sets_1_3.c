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
extern enum reg_class reg_class_subunion[25][25];
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ((int)LIM_REG_CLASSES); i += 1) {
    for (j = 0; j < ((int)LIM_REG_CLASSES); j += 1) {
        register HARD_REG_ELT_TYPE c;
        int k;
        unsigned int idx_i = i;
        unsigned int idx_j = j;
        ((c) = (reg_class_contents[idx_i]));
        ((c) |= (reg_class_contents[idx_j]));
        for (k = 0; k < ((int)LIM_REG_CLASSES); k += 1) {
            unsigned int idx_k = k;
            if (((HARD_REG_ELT_TYPE)(0)) == ((reg_class_contents[idx_k]) & ~(c)))
                goto subclass1;
            continue;
          subclass1:
            if (((HARD_REG_ELT_TYPE)(0)) == ((reg_class_contents[idx_k]) & ~(reg_class_contents[(int)reg_class_subunion[idx_i][idx_j]])))
                goto subclass2;
            reg_class_subunion[idx_i][idx_j] = (enum reg_class)idx_k;
          subclass2:
            ;
        }
    }
}
}
