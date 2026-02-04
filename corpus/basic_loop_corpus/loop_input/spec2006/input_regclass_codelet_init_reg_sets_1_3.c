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

HARD_REG_ELT_TYPE reg_class_contents[25];
enum reg_class reg_class_subunion[25][25];
unsigned int i;
unsigned int j;

void init_vars() {
    for (int idx = 0; idx < 25; idx++) {
        reg_class_contents[idx] = (HARD_REG_ELT_TYPE)1 << (idx % (sizeof(HARD_REG_ELT_TYPE) * 8 - 1));
        for (int jdx = 0; jdx < 25; jdx++) {
            reg_class_subunion[idx][jdx] = (enum reg_class)((idx + jdx) % LIM_REG_CLASSES);
        }
    }
}