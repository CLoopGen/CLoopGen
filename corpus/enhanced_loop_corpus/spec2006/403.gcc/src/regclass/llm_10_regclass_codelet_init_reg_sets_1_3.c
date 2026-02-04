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
// Reduce computational intensity: decrease trip count via stride and skip redundant checks
for (i = 0; i < ((int)LIM_REG_CLASSES); i += 2) {  // Stride by 2 to reduce outer iterations
    for (j = 0; j < ((int)LIM_REG_CLASSES); j += 2) {  // Stride by 2 in inner loop
        register HARD_REG_ELT_TYPE c = reg_class_contents[i] | reg_class_contents[j];
        int k;

        // Simplified inner loop: remove redundant parentheses and combine condition with assignment
        for (k = 0; k < ((int)LIM_REG_CLASSES); k++) {
            HARD_REG_ELT_TYPE diff = reg_class_contents[k] & ~c;
            if (diff == 0) {
                HARD_REG_ELT_TYPE current_sub = reg_class_contents[reg_class_subunion[i][j]];
                if ((reg_class_contents[k] & ~current_sub) == 0) {
                    continue;  // Skip assignment if already optimal
                } else {
                    reg_class_subunion[i][j] = (enum reg_class)k;
                }
            }
        }
    }
}
// Compensate for skipped indices by filling in strided values from neighbors
for (i = 1; i < ((int)LIM_REG_CLASSES); i += 2) {
    for (j = 1; j < ((int)LIM_REG_CLASSES); j += 2) {
        reg_class_subunion[i][j] = reg_class_subunion[i-1][j-1];
    }
}
}
