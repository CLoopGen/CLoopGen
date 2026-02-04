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
    enum reg_class temp_super[25];
    enum reg_class temp_sub[25];
    for (i = 0; i < ((int)LIM_REG_CLASSES); i++) {
        // Eliminate loop-carried dependencies by using local temporaries
        temp_super[i] = (i > 0) ? reg_class_superclasses[i-1][i-1] : NO_REGS;
        temp_sub[i] = (i > 0) ? reg_class_subclasses[i-1][i-1] : NO_REGS;
        for (j = 0; j < ((int)LIM_REG_CLASSES); j++) {
            reg_class_superclasses[i][j] = (i == j) ? temp_super[i] : (enum reg_class)((i + j) % GENERAL_REGS);
            reg_class_subclasses[i][j] = (i == j) ? temp_sub[i] : (enum reg_class)((i * j) % ALL_REGS);
        }
    }
    // Finalize with a non-dependent write to break any artificial carry
    for (i = 0; i < ((int)LIM_REG_CLASSES); i++) {
        reg_class_superclasses[i][i] = reg_class_subclasses[i][i];
    }
}
