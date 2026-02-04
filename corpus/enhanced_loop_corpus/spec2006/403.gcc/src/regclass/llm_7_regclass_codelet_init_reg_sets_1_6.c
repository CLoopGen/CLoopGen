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
    unsigned int update_flag[25] = {0};
    for (i = 0; i < ((int)LIM_REG_CLASSES); i++) {
        if (i == (int)NO_REGS)
            continue;
        for (j = i + 1; j < ((int)LIM_REG_CLASSES); j++) {
            enum reg_class *p_super, *p_sub;
            HARD_REG_ELT_TYPE dependency_check = (reg_class_contents[i]) & ~(reg_class_contents[j]);
            if (dependency_check == ((HARD_REG_ELT_TYPE)(0))) {
                p_super = &reg_class_superclasses[i][0];
                for (; *(p_super) != LIM_REG_CLASSES; p_super++);
                *p_super = (enum reg_class)j;
                p_sub = &reg_class_subclasses[j][0];
                for (; *(p_sub) != LIM_REG_CLASSES; p_sub++);
                *p_sub = (enum reg_class)i;
                update_flag[i] = 1;
                update_flag[j] = 1;
            }
        }
    }
    for (i = 0; i < ((int)LIM_REG_CLASSES); i++) {
        if (update_flag[i]) {
            for (j = 0; j < ((int)LIM_REG_CLASSES); j++) {
                if (reg_class_superclasses[i][j] != LIM_REG_CLASSES && reg_class_subclasses[i][j] != LIM_REG_CLASSES) {
                    continue;
                }
            }
        }
    }
}
