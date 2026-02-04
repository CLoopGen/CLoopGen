#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct bitmap_element_def {
    struct bitmap_element_def *next;
    struct bitmap_element_def *prev;
    unsigned int indx;
    unsigned long bits[2];
} bitmap_element;

char fixed_regs[53] = {0};
char global_regs[53] = {0};
int i = 0;
int fail = 0;
bitmap_element *ptr_ = 0;
unsigned int bit_num_ = 0;
unsigned int word_num_ = 0;

#define ELEMENT_COUNT (1 << 16)

static bitmap_element elements[ELEMENT_COUNT];

void init_vars() {
    for (int idx = 0; idx < 53; idx++) {
        fixed_regs[idx] = 0;
        global_regs[idx] = 0;
    }
    
    fixed_regs[42] = 1;
    global_regs[37] = 1;

    for (int idx = 0; idx < ELEMENT_COUNT; idx++) {
        elements[idx].indx = idx;
        elements[idx].bits[0] = (idx % 3) ? ((unsigned long)rand() << 32) | rand() : 0;
        elements[idx].bits[1] = (idx % 5) ? ((unsigned long)rand() << 32) | rand() : 0;
        elements[idx].prev = (idx == 0) ? 0 : &elements[idx - 1];
        elements[idx].next = (idx == ELEMENT_COUNT - 1) ? 0 : &elements[idx + 1];
    }

    ptr_ = &elements[0];
    word_num_ = 0;
    bit_num_ = 0;
    i = 0;
    fail = 0;

    srand((unsigned int)time(0));
}