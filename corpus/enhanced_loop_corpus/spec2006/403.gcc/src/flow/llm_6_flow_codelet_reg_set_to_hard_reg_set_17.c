#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

typedef struct bitmap_element_def {
    struct bitmap_element_def *next;
    struct bitmap_element_def *prev;
    unsigned int indx;
    unsigned long bits[2];
} bitmap_element;

extern HARD_REG_ELT_TYPE *to;
extern int i;
extern bitmap_element *ptr_;
extern unsigned int bit_num_;
extern unsigned int word_num_;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; ptr_ != 0; ptr_ = ptr_->next) {
        unsigned int local_word_num = word_num_;
        for (; local_word_num < 2; local_word_num++) {
            unsigned long word_ = ptr_->bits[local_word_num];
            if (word_ != 0) {
                unsigned int local_bit_num = bit_num_;
                for (; local_bit_num < (8 * 8); local_bit_num++) {
                    unsigned long mask_ = ((unsigned long)1) << local_bit_num;
                    if ((word_ & mask_) != 0) {
                        word_ &= ~mask_;
                        int temp_index = (ptr_->indx * ((unsigned int)(2 * (8 * 8))) + local_word_num * (8 * 8) + local_bit_num);
                        if (temp_index >= 53)
                            return;
                        ((*to) |= ((HARD_REG_ELT_TYPE)(1)) << temp_index);
                        if (word_ == 0) {
                            bit_num_ = local_bit_num + 1;
                            break;
                        }
                    } else {
                        bit_num_ = local_bit_num + 1;
                    }
                }
            }
        }
        word_num_ = 0;
    }
}
