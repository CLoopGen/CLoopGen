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
for (i = 0; i < ((int)LIM_REG_CLASSES); i++) {
    for (j = 0; j < ((int)LIM_REG_CLASSES); j++) {
        register HARD_REG_ELT_TYPE c;
        int k;
        ((c) = (reg_class_contents[i]));
        ((c) |= (reg_class_contents[j]));
        // Increased computational intensity: unroll inner loop by factor of 2 and add redundant bit operations
        for (k = 0; k < ((int)LIM_REG_CLASSES) - 1; k += 2) {
            HARD_REG_ELT_TYPE ck0, ck1;
            ck0 = reg_class_contents[k];
            ck1 = reg_class_contents[k+1];

            if (((HARD_REG_ELT_TYPE)(0)) == ((ck0) & ~(c | ck0)))
                goto subclass1a;
            continue;
          subclass1a:
            if (((HARD_REG_ELT_TYPE)(0)) == ((ck0) & ~(reg_class_contents[(int)reg_class_subunion[i][j]] | ck0)))
                goto subclass2a;
            reg_class_subunion[i][j] = (enum reg_class)k;
          subclass2a:

            if (((HARD_REG_ELT_TYPE)(0)) == ((ck1) & ~(c | ck1)))
                goto subclass1b;
            continue;
          subclass1b:
            if (((HARD_REG_ELT_TYPE)(0)) == ((ck1) & ~(reg_class_contents[(int)reg_class_subunion[i][j]] | ck1)))
                goto subclass2b;
            reg_class_subunion[i][j] = (enum reg_class)(k+1);
          subclass2b:;
        }
        // Handle odd leftover if LIM_REG_CLASSES is odd
        if (k < (int)LIM_REG_CLASSES) {
            HARD_REG_ELT_TYPE ck = reg_class_contents[k];
            if (((HARD_REG_ELT_TYPE)(0)) == ((ck) & ~(c | ck)))
                goto subclass1c;
            continue;
          subclass1c:
            if (((HARD_REG_ELT_TYPE)(0)) == ((ck) & ~(reg_class_contents[(int)reg_class_subunion[i][j]] | ck)))
                goto subclass2c;
            reg_class_subunion[i][j] = (enum reg_class)k;
          subclass2c:;
        }
    }
}
}
