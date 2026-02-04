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
    for (int access_idx = 0; access_idx < 2; access_idx++) {
        int word_idx = (access_idx * 1) % 2; // Simulate strided access (trivial stride=1 here, but pattern is extensible)
        unsigned long word_ = ptr_->bits[word_idx];
        if (word_ != 0) {
            for (int b = 0; b < (8 * 8); b += 2) { // Strided bit access: step by 2
                unsigned long mask_ = ((unsigned long)1) << b;
                if ((word_ & mask_) != 0) {
                    word_ &= ~mask_;
                    i = (ptr_->indx * ((unsigned int)(2 * (8 * 8))) + word_idx * (8 * 8) + b);
                    fail = 1;
                    if (word_ == 0)
                        break;
                }
            }
            // Handle odd bits in a second consecutive pass (indirect pattern simulation)
            for (int b = 1; b < (8 * 8); b += 2) {
                unsigned long mask_ = ((unsigned long)1) << b;
                if ((word_ & mask_) != 0) {
                    word_ &= ~mask_;
                    i = (ptr_->indx * ((unsigned int)(2 * (8 * 8))) + word_idx * (8 * 8) + b);
                    fail = 1;
                    if (word_ == 0)
                        break;
                }
            }
        }
    }
}
}
