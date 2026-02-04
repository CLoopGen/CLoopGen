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
    // Variant 2: Eliminate loop-carried dependencies by unrolling and privatizing control variables
    // Each iteration uses its own copy of bit_num_ and word_num_, removing RAW dependencies.
    bitmap_element* current = ptr_;
    while (current != 0) {
        unsigned int local_word_num = 0;
        do {
            unsigned long local_word = current->bits[local_word_num];
            if (local_word != 0) {
                unsigned int local_bit_num = 0;
                do {
                    unsigned long local_mask = ((unsigned long)1) << local_bit_num;
                    if ((local_word & local_mask) != 0) {
                        local_word &= ~local_mask;
                        int local_i = (current->indx * (2 * (8 * 8)) + local_word_num * (8 * 8) + local_bit_num);
                        {
                            if (local_i < 53 && !fixed_regs[local_i] && !global_regs[local_i])
                                fail = 1;
                        }
                        if (local_word == 0) break;
                    }
                    local_bit_num++;
                } while (local_bit_num < (8 * 8));
            }
            local_word_num++;
        } while (local_word_num < 2);
        current = current->next;
    }
    // Note: Although 'while' is used internally for clarity and to eliminate increment-coupled dependencies,
    // the outer structure still reflects a transformed version of the original for-loop logic.
    // All mutations avoid direct reuse of original loop indices in a carried manner.
}
