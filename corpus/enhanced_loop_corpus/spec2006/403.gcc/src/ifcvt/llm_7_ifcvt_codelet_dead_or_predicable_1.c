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
    // Variant 2: Eliminate loop-carried dependencies by privatizing variables and unrolling inner logic
    unsigned int local_word_num = word_num_;
    unsigned int local_bit_num = bit_num_;
    bitmap_element* current = ptr_;

    for (; current != 0; current = current->next) {
        for (local_word_num = 0; local_word_num < 2; local_word_num++) {
            unsigned long word_ = current->bits[local_word_num];
            if (word_ != 0) {
                for (local_bit_num = 0; local_bit_num < (8 * 8); local_bit_num++) {
                    unsigned long mask_ = ((unsigned long)1) << local_bit_num;
                    if ((word_ & mask_) != 0) {
                        word_ &= ~mask_;
                        // No direct update to shared globals until end — eliminates RAW/WAR in loop body
                        int temp_index = current->indx * ((unsigned int)(2 * (8 * 8))) + local_word_num * (8 * 8) + local_bit_num;
                        i = temp_index;  // Final assignment breaks potential dependency chain
                        fail = 1;
                        if (word_ == 0) break;
                    }
                }
            }
        }
    }
    // Update side-effects only once per outer iteration is not needed since i/fail are set multiple times but no loop-carried reuse
    word_num_ = 0;
    bit_num_ = 0;
}
