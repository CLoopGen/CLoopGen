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
extern enum reg_class class;
extern unsigned int regno;
extern unsigned int nwords;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < nwords; i++)
    if (!((reg_class_contents[(int)class]) & (((HARD_REG_ELT_TYPE)(1)) << (regno + i))))
        break;

}
