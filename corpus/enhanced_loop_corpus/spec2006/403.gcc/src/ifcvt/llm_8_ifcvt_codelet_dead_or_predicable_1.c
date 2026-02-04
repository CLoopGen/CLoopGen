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
    for (; word_num_ < 2; word_num_++) {
        unsigned long word_ = ptr_->bits[word_num_];
        if (word_ != 0) {
            // Unrolled inner loop: process two bits per iteration to reduce trip count and increase arithmetic intensity
            for (; bit_num_ < (8 * 8) - 1; bit_num_ += 2) {
                unsigned long mask1_ = ((unsigned long)1) << bit_num_;
                unsigned long mask2_ = ((unsigned long)1) << (bit_num_ + 1);
                int found1 = (word_ & mask1_) != 0;
                int found2 = (word_ & mask2_) != 0;

                if (found1 || found2) {
                    if (found1) {
                        word_ &= ~mask1_;
                        i = ptr_->indx * (2U * 64U) + word_num_ * 64U + bit_num_;
                        fail = 1;
                    }
                    if (found2 && word_ != 0) {
                        word_ &= ~mask2_;
                        i = ptr_->indx * (2U * 64U) + word_num_ * 64U + bit_num_ + 1;
                        fail = 1;
                    }
                    if (word_ == 0) break;
                }
            }
            // Handle leftover odd bit
            if (bit_num_ < (8 * 8) && word_ != 0) {
                unsigned long mask_ = ((unsigned long)1) << bit_num_;
                if ((word_ & mask_) != 0) {
                    word_ &= ~mask_;
                    i = ptr_->indx * (2U * 64U) + word_num_ * 64U + bit_num_;
                    fail = 1;
                }
            }
        }
        bit_num_ = 0;
    }
    word_num_ = 0;
}
}
