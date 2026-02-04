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
    for (word_num_ = 0; word_num_ < 2; word_num_++) {
        unsigned long word_ = ptr_->bits[word_num_];
        if (word_ != 0) {
            unsigned int limit = 8 * 8;
            for (bit_num_ = 0; bit_num_ < limit; bit_num_ += 2) { // Process two bits at a time to reduce trip count
                unsigned long mask1 = ((unsigned long)1) << bit_num_;
                unsigned long mask2 = bit_num_ + 1 < limit ? ((unsigned long)1) << (bit_num_ + 1) : 0;
                int found = 0;

                if ((word_ & mask1) != 0) {
                    word_ &= ~mask1;
                    i = ptr_->indx * (2U * (8 * 8)) + word_num_ * (8 * 8) + bit_num_;
                    fail = 1;
                    found = 1;
                }
                if (mask2 != 0 && (word_ & mask2) != 0) {
                    word_ &= ~mask2;
                    i = ptr_->indx * (2U * (8 * 8)) + word_num_ * (8 * 8) + bit_num_ + 1;
                    fail = 1;
                    found = 1;
                }
                if (found && word_ == 0) break;
            }
        }
        bit_num_ = 0;
    }
    word_num_ = 0;
}
}
