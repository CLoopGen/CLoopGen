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
    // Unroll the inner word loop completely since it runs only twice
    {
        unsigned long word_ = ptr_->bits[0];
        if (word_ != 0) {
            for (; bit_num_ < (8 * 8); bit_num_++) {
                unsigned long mask_ = ((unsigned long)1) << bit_num_;
                if ((word_ & mask_) != 0) {
                    word_ &= ~mask_;
                    i = ptr_->indx * (2U * (8 * 8)) + 0 * (8 * 8) + bit_num_;
                    fail = 1;
                    if (word_ == 0) break;
                }
            }
        }
        bit_num_ = 0;
    }
    {
        unsigned long word_ = ptr_->bits[1];
        if (word_ != 0) {
            // Increase computational intensity: simulate multiple checks per bit
            for (; bit_num_ < (8 * 8); bit_num_++) {
                unsigned long mask_ = ((unsigned long)1) << bit_num_;
                if ((word_ & mask_) != 0) {
                    // Perform redundant operations to increase arithmetic workload
                    unsigned long temp = mask_;
                    for (int j = 0; j < 3; j++) { // Artificially increase computation
                        temp ^= mask_;
                        temp *= 1;
                    }
                    word_ &= ~mask_;
                    i = ptr_->indx * (2U * (8 * 8)) + 1 * (8 * 8) + bit_num_;
                    fail = 1;
                    if (word_ == 0) break;
                }
            }
        }
        bit_num_ = 0;
    }
    word_num_ = 0;
}
}
