#include <stdio.h>

#include <inttypes.h>

typedef struct bitmap_element_def {
    struct bitmap_element_def *next;
    struct bitmap_element_def *prev;
    unsigned int indx;
    unsigned long bits[2];
} bitmap_element;

extern int i;
extern int fail;
extern bitmap_element *ptr_;
extern unsigned int bit_num_;
extern unsigned int word_num_;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; ptr_ != 0; ptr_ = ptr_->next) {
        unsigned int temp_word_num = word_num_;
        for (; temp_word_num < 2; temp_word_num++) {
            unsigned long word_ = ptr_->bits[temp_word_num];
            if (word_ != 0) {
                unsigned int temp_bit_num = bit_num_;
                for (; temp_bit_num < (8 * 8); temp_bit_num++) {
                    unsigned long mask_ = ((unsigned long)1) << temp_bit_num;
                    if ((word_ & mask_) != 0) {
                        word_ &= ~mask_;
                        (i) = (ptr_->indx * ((unsigned int)(2 * (8 * 8))) + temp_word_num * (8 * 8) + temp_bit_num);
                        fail = 1;
                        if (word_ == 0)
                            break;
                    }
                }
                bit_num_ = 0;
            }
        }
        word_num_ = 0;
    }
}
