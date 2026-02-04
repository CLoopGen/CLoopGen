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


extern enum reg_class reg_class_superclasses[25][25];
extern enum reg_class reg_class_subclasses[25][25];
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Access the arrays with a stride of 2, wrapping around using modulo to ensure bounds safety
    for (i = 0; i < ((int)LIM_REG_CLASSES); i++) {
        for (j = 0; j < ((int)LIM_REG_CLASSES); j += 2) {
            unsigned int k = (j + 2) % LIM_REG_CLASSES;
            reg_class_superclasses[i][j] = LIM_REG_CLASSES;
            if (k < LIM_REG_CLASSES) {
                reg_class_superclasses[i][k] = LIM_REG_CLASSES;
            }
            reg_class_subclasses[i][j] = LIM_REG_CLASSES;
            if (k < LIM_REG_CLASSES) {
                reg_class_subclasses[i][k] = LIM_REG_CLASSES;
            }
        }
    }
}
