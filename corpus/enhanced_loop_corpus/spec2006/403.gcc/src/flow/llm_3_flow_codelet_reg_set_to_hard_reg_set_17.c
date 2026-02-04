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
for (; ptr_ != 0; ptr_ = ptr_->next) {
    unsigned long *bits_ptr = ptr_->bits;
    for (int access_idx = 0; access_idx < 2; access_idx++) {
        unsigned long word_ = *(bits_ptr + access_idx); // Strided-like indirect access pattern
        if (word_ != 0) {
            for (int bit_offset = 0; bit_offset < (8 * 8); bit_offset += 2) { // Strided access: step by 2
                int b = bit_offset;
                unsigned long mask_ = ((unsigned long)1) << b;
                if ((word_ & mask_) != 0) {
                    word_ &= ~mask_;
                    i = (ptr_->indx * (2U * (8 * 8)) + access_idx * (8 * 8) + b);
                    {
                        if (i >= 53)
                            return;
                        (*to) |= ((HARD_REG_ELT_TYPE)1) << i;
                    }
                    if (word_ == 0)
                        break;
                }
                // Second access in stride
                if ((bit_offset + 1) < (8 * 8)) {
                    b = bit_offset + 1;
                    mask_ = ((unsigned long)1) << b;
                    if ((word_ & mask_) != 0) {
                        word_ &= ~mask_;
                        i = (ptr_->indx * (2U * (8 * 8)) + access_idx * (8 * 8) + b);
                        {
                            if (i >= 53)
                                return;
                            (*to) |= ((HARD_REG_ELT_TYPE)1) << i;
                        }
                        if (word_ == 0)
                            break;
                    }
                }
            }
        }
    }
}
}
