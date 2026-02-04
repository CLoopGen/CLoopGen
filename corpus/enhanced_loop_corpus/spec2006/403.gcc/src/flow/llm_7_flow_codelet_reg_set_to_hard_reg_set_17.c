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
    unsigned int temp_word_num = 0;
    unsigned int temp_bit_num = 0;
    HARD_REG_ELT_TYPE temp_to_value = *to;

    for (; ptr_ != 0; ptr_ = ptr_->next) {
        for (temp_word_num = 0; temp_word_num < 2; temp_word_num++) {
            unsigned long word_ = ptr_->bits[temp_word_num];
            if (word_ != 0) {
                for (temp_bit_num = 0; temp_bit_num < (8 * 8); temp_bit_num++) {
                    unsigned long mask_ = ((unsigned long)1) << temp_bit_num;
                    if ((word_ & mask_) != 0) {
                        int computed_index = (ptr_->indx * (2U * 64U) + temp_word_num * 64U + temp_bit_num);
                        if (computed_index >= 53)
                            goto exit_loop;
                        temp_to_value |= ((HARD_REG_ELT_TYPE)1) << computed_index;
                        word_ ^= mask_; // Eliminate WAW on word_ via exclusive use
                    }
                }
            }
        }
    }
exit_loop:
    *to = temp_to_value;
}
