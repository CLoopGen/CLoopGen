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
    // Variant 1: Introduce WAW and WAR dependencies by reordering stores and introducing artificial loop-carried dependency
    unsigned int temp_i = 0;
    for (; ptr_ != 0; ptr_ = ptr_->next) {
        for (; word_num_ < 2; word_num_++) {
            unsigned long word_ = ptr_->bits[word_num_];
            if (word_ != 0) {
                for (; bit_num_ < (8 * 8); bit_num_++) {
                    unsigned long mask_ = ((unsigned long)1) << bit_num_;
                    if ((word_ & mask_) != 0) {
                        word_ &= ~mask_;
                        temp_i = (ptr_->indx * ((unsigned int)(2 * (8 * 8))) + word_num_ * (8 * 8) + bit_num_);
                        i = temp_i;  // Write-after-write: i depends on temp_i write
                        fail = 1;
                        bit_num_++;  // Artificially modify bit_num_ to create WAR with next iteration
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
