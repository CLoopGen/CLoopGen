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
    const size_t data_size = 128 * 1024 * 1024; // ~128MB of data
    const unsigned long bits_per_word = sizeof(HARD_REG_ELT_TYPE) * 8;

    nwords = (unsigned int)((data_size + sizeof(HARD_REG_ELT_TYPE) - 1) / sizeof(HARD_REG_ELT_TYPE));
    regno = 0;
    class = GENERAL_REGS;

    for (int idx = 0; idx < 25; idx++) {
        if (idx == GENERAL_REGS) {
            reg_class_contents[idx] = ~(HARD_REG_ELT_TYPE)0;
        } else {
            reg_class_contents[idx] = 0;
        }
    }

    i = 0;
}