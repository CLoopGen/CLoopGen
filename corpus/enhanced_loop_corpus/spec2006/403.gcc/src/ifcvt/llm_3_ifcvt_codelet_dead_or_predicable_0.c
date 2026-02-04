#include <stdio.h>

#include <inttypes.h>

typedef struct bitmap_element_def {
    struct bitmap_element_def *next;
    struct bitmap_element_def *prev;
    unsigned int indx;
    unsigned long bits[2];
} bitmap_element;

extern char fixed_regs[53];
extern char global_regs[53];
extern int i;
extern int fail;
extern bitmap_element *ptr_;
extern unsigned int bit_num_;
extern unsigned int word_num_;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; ptr_ != 0; ptr_ = ptr_->next) {
    for (int access_idx = 0; access_idx < 2; access_idx++) {
        int w = (access_idx * 1) % 2; // Strided access pattern: could be extended to larger strides
        unsigned long word_ = ptr_->bits[w];
        if (word_ != 0) {
            for (int b = (8 * 8) - 1; b >= 0; b--) { // Reverse traversal (consecutive but backward)
                unsigned long mask_ = ((unsigned long)1) << b;
                if ((word_ & mask_) != 0) {
                    word_ &= ~mask_;
                    i = (ptr_->indx * ((unsigned int)(2 * (8 * 8))) + w * (8 * 8) + b);
                    {
                        if (i < 53 && !fixed_regs[i] && !global_regs[i])
                            fail = 1;
                    }
                    if (word_ == 0)
                        break;
                }
            }
        }
    }
}
}
