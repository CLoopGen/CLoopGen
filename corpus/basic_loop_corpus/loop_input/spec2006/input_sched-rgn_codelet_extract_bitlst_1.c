#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int *first_member;
    int nr_members;
} bitlst;

int bitlst_table_last;
int *bitlst_table;
bitlst *bl;
int i;
unsigned int word_num_;
unsigned int bit_num_;
unsigned int size_;
unsigned long *ptr_;

void init_vars() {
    const unsigned int data_size_mb = 64;
    const unsigned int element_size = sizeof(unsigned long);
    const unsigned int words_per_cache_line = 8;
    size_ = (data_size_mb * 1024 * 1024) / element_size;

    ptr_ = (unsigned long *)aligned_alloc(64, size_ * element_size);
    if (!ptr_) exit(1);

    bitlst_table = (int *)malloc(size_ * words_per_cache_line * 8 * sizeof(int));
    if (!bitlst_table) exit(1);
    bitlst_table_last = 0;

    bl = (bitlst *)malloc(sizeof(bitlst));
    if (!bl) exit(1);
    bl->first_member = NULL;
    bl->nr_members = 0;

    i = 0;
    word_num_ = 0;
    bit_num_ = 0;

    srand((unsigned int)time(NULL));
    for (unsigned int j = 0; j < size_; j++) {
        ptr_[j] = rand() & ((j % 3) ? 0xFFFF : 0xFFFFFFF0); 
    }
}