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
    FLOAT_INT_REGS,
    INT_SSE_REGS,
    FLOAT_INT_SSE_REGS,
    ALL_REGS,
    LIM_REG_CLASSES
};

HARD_REG_ELT_TYPE reg_class_contents[25];
enum reg_class class;
unsigned int regno;
unsigned int nwords;
unsigned int i;

void init_vars() {
    class = GENERAL_REGS;
    regno = 0;
    nwords = 16777216;  // ~16M words to target ~0.01s runtime on modern CPU

    for (int r = 0; r < 25; r++) {
        if (r == GENERAL_REGS) {
            reg_class_contents[r] = 0xFFFFFFFFUL;
        } else {
            reg_class_contents[r] = 0;
        }
    }

    i = 0;
}