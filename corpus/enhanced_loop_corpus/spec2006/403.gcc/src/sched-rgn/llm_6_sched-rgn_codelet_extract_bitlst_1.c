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
    for (word_num_ = (0) / (unsigned int)((unsigned int)(8 * 8)); word_num_ < size_; word_num_++) {
        unsigned long word_ = ptr_[word_num_];
        bit_num_ = 0;
        if (word_ != 0) {
            unsigned long temp_word = word_;
            for (; bit_num_ < ((unsigned int)(8 * 8)); bit_num_++) {
                unsigned long _mask = (unsigned long)1 << bit_num_;
                if ((temp_word & _mask) != 0) {
                    temp_word &= ~_mask;
                    (i) = word_num_ * ((unsigned int)(8 * 8)) + bit_num_;
                    {
                        bitlst_table[bitlst_table_last] = i;
                        bitlst_table_last++;
                        (bl->nr_members)++;
                    }
                    if (temp_word == 0)
                        break;
                }
            }
        }
    }
}
