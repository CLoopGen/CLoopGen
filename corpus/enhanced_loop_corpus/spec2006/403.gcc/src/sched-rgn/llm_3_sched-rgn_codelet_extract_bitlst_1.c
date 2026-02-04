#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int *first_member;
    int nr_members;
} bitlst;

extern int bitlst_table_last;
extern int *bitlst_table;
extern bitlst *bl;
extern int i;
extern unsigned int word_num_;
extern unsigned int bit_num_;
extern unsigned int size_;
extern unsigned long *ptr_;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every other word first, then fill in (strided traversal)
    // First pass: even-indexed words
    for (word_num_ = (0) / (unsigned int)((unsigned int)(8 * 8)); word_num_ < size_; word_num_ += 2) {
        unsigned long word_ = ptr_[word_num_];
        if (word_ != 0) {
            for (bit_num_ = 0; bit_num_ < ((unsigned int)(8 * 8)); bit_num_++) {
                unsigned long _mask = (unsigned long)1 << bit_num_;
                if ((word_ & _mask) != 0) {
                    word_ &= ~_mask;
                    i = word_num_ * ((unsigned int)(8 * 8)) + bit_num_;
                    bitlst_table[bitlst_table_last++] = i;
                    (bl->nr_members)++;
                    if (word_ == 0)
                        break;
                }
            }
        }
    }
    // Second pass: odd-indexed words
    for (word_num_ = (1) / (unsigned int)((unsigned int)(8 * 8)) + (1 % ((unsigned int)(8 * 8)) ? 1 : 0); 
         word_num_ < size_; 
         word_num_ += 2) {
        unsigned long word_ = ptr_[word_num_];
        if (word_ != 0) {
            for (bit_num_ = 0; bit_num_ < ((unsigned int)(8 * 8)); bit_num_++) {
                unsigned long _mask = (unsigned long)1 << bit_num_;
                if ((word_ & _mask) != 0) {
                    word_ &= ~_mask;
                    i = word_num_ * ((unsigned int)(8 * 8)) + bit_num_;
                    bitlst_table[bitlst_table_last++] = i;
                    (bl->nr_members)++;
                    if (word_ == 0)
                        break;
                }
            }
        }
    }
}
