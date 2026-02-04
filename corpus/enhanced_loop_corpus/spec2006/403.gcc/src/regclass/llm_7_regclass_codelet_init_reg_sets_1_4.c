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
HARD_REG_ELT_TYPE temp_contents[25];
for (i = 0; i < ((int)LIM_REG_CLASSES); i++) {
    temp_contents[i] = reg_class_contents[i];
}
for (i = 0; i < ((int)LIM_REG_CLASSES); i++) {
    for (j = i; j < ((int)LIM_REG_CLASSES); j++) { // Introduce loop-carried dependency via index dependency (j starts at i)
        register HARD_REG_ELT_TYPE c;
        int k;
        ((c) = (temp_contents[i]));
        ((c) |= (temp_contents[j]));
        for (k = 0; k < ((int)LIM_REG_CLASSES); k++) {
            if (((HARD_REG_ELT_TYPE)(0)) == ((c) & ~(temp_contents[k]))) {
                reg_class_superunion[i][j] = (enum reg_class)k;
                reg_class_superunion[j][i] = (enum reg_class)k; // Symmetric write introduces WAW hazard potential
                break;
            }
        }
    }
}
}
