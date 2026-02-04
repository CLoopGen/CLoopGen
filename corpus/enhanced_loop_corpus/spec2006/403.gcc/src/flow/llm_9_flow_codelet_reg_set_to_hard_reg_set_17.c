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
for (; ptr_ != 0 && ptr_->next != 0; ptr_ = ptr_->next->next) {
    for (word_num_ = 0; word_num_ < 2; word_num_++) {
        unsigned long word_ = ptr_->bits[word_num_];
        unsigned long temp_word = word_;
        bit_num_ = 0;
        while (temp_word != 0) {
            unsigned long lsb = temp_word & (~temp_word + 1);
            bit_num_ = __builtin_ctzl(lsb);
            temp_word ^= lsb;
            i = (ptr_->indx * ((unsigned int)(2 * (8 * 8))) + word_num_ * (8 * 8) + bit_num_);
            if (i >= 53)
                return;
            (*to |= ((HARD_REG_ELT_TYPE)(1)) << i);
        }
    }
    for (word_num_ = 0; word_num_ < 2; word_num_++) {
        unsigned long word_ = ptr_->next->bits[word_num_];
        unsigned long temp_word = word_;
        bit_num_ = 0;
        while (temp_word != 0) {
            unsigned long lsb = temp_word & (~temp_word + 1);
            bit_num_ = __builtin_ctzl(lsb);
            temp_word ^= lsb;
            i = (ptr_->next->indx * ((unsigned int)(2 * (8 * 8))) + word_num_ * (8 * 8) + bit_num_);
            if (i >= 53)
                return;
            (*to |= ((HARD_REG_ELT_TYPE)(1)) << i);
        }
    }
    word_num_ = 0;
}
}
