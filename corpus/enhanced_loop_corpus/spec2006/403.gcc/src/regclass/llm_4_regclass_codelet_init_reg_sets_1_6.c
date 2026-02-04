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
for (i = 0; i < ((int)LIM_REG_CLASSES); i++) {
    if (i != (int)NO_REGS) {
        for (j = i + 1; j < ((int)LIM_REG_CLASSES); j++) {
            enum reg_class *p;
            if (((HARD_REG_ELT_TYPE)(0)) == ((reg_class_contents[i]) & ~(reg_class_contents[j]))) {
                p = &reg_class_superclasses[i][0];
                while (*p != LIM_REG_CLASSES)
                    p++;
                *p = (enum reg_class)j;
                p = &reg_class_subclasses[j][0];
                while (*p != LIM_REG_CLASSES)
                    p++;
                *p = (enum reg_class)i;
            }
        }
    }
}
}
