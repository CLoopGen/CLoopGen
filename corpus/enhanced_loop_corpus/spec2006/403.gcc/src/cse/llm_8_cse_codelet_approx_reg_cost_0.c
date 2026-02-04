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


typedef struct bitmap_element_def {
    struct bitmap_element_def *next;
    struct bitmap_element_def *prev;
    unsigned int indx;
    unsigned long bits[2];
} bitmap_element;

extern const enum reg_class regclass_map[53];
extern char fixed_regs[53];
extern char global_regs[53];
extern int i;
extern int cost;
extern int hardregs;
extern bitmap_element *ptr_;
extern unsigned int bit_num_;
extern unsigned int word_num_;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; ptr_ != 0; ptr_ = ptr_->next) {
        for (word_num_ = 0; word_num_ < 2; word_num_++) {
            unsigned long word_ = ptr_->bits[word_num_];
            if (word_ != 0) {
                for (bit_num_ = 0; bit_num_ < (8 * 8); bit_num_++) {
                    unsigned long mask_ = ((unsigned long)1) << bit_num_;
                    if ((word_ & mask_) != 0) {
                        word_ &= ~mask_;
                        i = ptr_->indx * (2U * 64U) + word_num_ * 64U + bit_num_;
                        if (!(i == 20 || i == 6 || i == 7 || i == 16 || (i >= 53 && i <= 57) || (i < 53 && (i == 20 || i == 6 || fixed_regs[i] || global_regs[i]) && regclass_map[i] != NO_REGS))) {
                            if (i < 53)
                                hardregs++;
                            cost += (i < 53) ? 2 : 1;
                        }
                        if (word_ == 0) break;
                    }
                }
                bit_num_ = 0;
            }
        }
        word_num_ = 0;
    }
}
