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
    for (int w = 0; w < 2; w++) {
        unsigned long word_ = ptr_->bits[w];
        if (word_ != 0) {
            for (int b = 0; b < (8 * 8); b++) {
                unsigned long mask_ = ((unsigned long)1) << b;
                if ((word_ & mask_) != 0) {
                    word_ &= ~mask_;
                    i = (ptr_->indx * ((unsigned int)(2 * (8 * 8))) + w * (8 * 8) + b);
                    fail = 1;
                    if (word_ == 0)
                        break;
                }
            }
        }
    }
}
}
