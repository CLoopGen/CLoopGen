#include <stdio.h>

#include <inttypes.h>

typedef struct bitmap_element_def {
    struct bitmap_element_def *next;
    struct bitmap_element_def *prev;
    unsigned int indx;
    unsigned long bits[2];
} bitmap_element;

extern char fixed_regs[53];
extern char global_regs[53];
extern int i;
extern int fail;
extern bitmap_element *ptr_;
extern unsigned int bit_num_;
extern unsigned int word_num_;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; ptr_ != 0; ptr_ = ptr_->next) {
    if (ptr_->bits[0] == 0 && ptr_->bits[1] == 0) {
        word_num_ = 0;
        bit_num_ = 0;
        continue;
    }
    for (; word_num_ < 2; word_num_++) {
        unsigned long word_ = ptr_->bits[word_num_];
        if (word_ == 0) {
            bit_num_ = 0;
            continue;
        }
        for (; bit_num_ < (8 * 8); bit_num_++) {
            unsigned long mask_ = ((unsigned long)1) << bit_num_;
            if ((word_ & mask_) == 0) continue;
            word_ &= ~mask_;
            i = ptr_->indx * ((unsigned int)(2 * (8 * 8))) + word_num_ * (8 * 8) + bit_num_;
            {
                if (i < 53 && !fixed_regs[i] && !global_regs[i])
                    fail = 1;
            }
            if (word_ == 0) break;
        }
        bit_num_ = 0;
    }
    word_num_ = 0;
}
}
