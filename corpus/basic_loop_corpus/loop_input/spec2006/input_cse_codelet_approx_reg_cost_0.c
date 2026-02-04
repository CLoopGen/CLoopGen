#include <stdio.h>
#include <stdlib.h>
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

typedef struct bitmap_element_def {
    struct bitmap_element_def *next;
    struct bitmap_element_def *prev;
    unsigned int indx;
    unsigned long bits[2];
} bitmap_element;

const enum reg_class regclass_map[53] = {
    GENERAL_REGS, GENERAL_REGS, GENERAL_REGS, GENERAL_REGS,
    GENERAL_REGS, GENERAL_REGS, NO_REGS,      NO_REGS,
    GENERAL_REGS, GENERAL_REGS, GENERAL_REGS, GENERAL_REGS,
    GENERAL_REGS, GENERAL_REGS, GENERAL_REGS, GENERAL_REGS,
    NO_REGS,      GENERAL_REGS, GENERAL_REGS, GENERAL_REGS,
    NO_REGS,      GENERAL_REGS, GENERAL_REGS, GENERAL_REGS,
    GENERAL_REGS, GENERAL_REGS, GENERAL_REGS, GENERAL_REGS,
    GENERAL_REGS, GENERAL_REGS, GENERAL_REGS, GENERAL_REGS,
    GENERAL_REGS, GENERAL_REGS, GENERAL_REGS, GENERAL_REGS,
    GENERAL_REGS, GENERAL_REGS, GENERAL_REGS, GENERAL_REGS,
    GENERAL_REGS, GENERAL_REGS, GENERAL_REGS, GENERAL_REGS,
    GENERAL_REGS, GENERAL_REGS, GENERAL_REGS, GENERAL_REGS,
    GENERAL_REGS, GENERAL_REGS, GENERAL_REGS, GENERAL_REGS,
    GENERAL_REGS, GENERAL_REGS, GENERAL_REGS
};

char fixed_regs[53] = {
    0, 0, 0, 0,
    0, 0, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
    1, 0, 0, 0,
    1, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0
};

char global_regs[53] = {
    0, 0, 0, 0,
    0, 0, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
    1, 0, 0, 0,
    1, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0
};

int i;
int cost;
int hardregs;
bitmap_element *ptr_;
unsigned int bit_num_;
unsigned int word_num_;

void init_vars() {
    const size_t total_data_size = 16 * 1024 * 1024;
    const size_t element_size = sizeof(bitmap_element);
    const size_t element_count = total_data_size / element_size;

    bitmap_element *elements = calloc(element_count, element_size);
    if (!elements) {
        exit(1);
    }

    for (size_t idx = 0; idx < element_count; idx++) {
        elements[idx].indx = (unsigned int)(idx % 1000);
        elements[idx].bits[0] = (idx % 7 == 0) ? 0x1UL : ((idx * 11) & 0xFFFFFUL);
        elements[idx].bits[1] = (idx % 13 == 0) ? 0x2UL : ((idx * 17) & 0xABCDEFUL);

        if (idx > 0) {
            elements[idx].prev = &elements[idx - 1];
        } else {
            elements[idx].prev = NULL;
        }

        if (idx < element_count - 1) {
            elements[idx].next = &elements[idx + 1];
        } else {
            elements[idx].next = NULL;
        }
    }

    ptr_ = &elements[0];
    bit_num_ = 0;
    word_num_ = 0;
    i = 0;
    cost = 0;
    hardregs = 0;
}