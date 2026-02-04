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

int i;
int fail;
bitmap_element *ptr_;
unsigned int bit_num_;
unsigned int word_num_;

#define NUM_ELEMENTS 100000

static bitmap_element elements[NUM_ELEMENTS];
static unsigned long pattern_seed = 12345;

void init_vars() {
    i = 0;
    fail = 0;
    bit_num_ = 0;
    word_num_ = 0;

    // Initialize all elements
    for (int idx = 0; idx < NUM_ELEMENTS; idx++) {
        elements[idx].indx = idx;
        elements[idx].bits[0] = (idx % 3) ? ((pattern_seed + idx) * 0x9e3779b9UL) : 0;
        elements[idx].bits[1] = (idx % 4) ? ((pattern_seed + idx + 1) * 0x9e3779b9UL << 1) : 0;
        
        if (idx > 0) {
            elements[idx].prev = &elements[idx - 1];
        } else {
            elements[idx].prev = NULL;
        }
        
        if (idx < NUM_ELEMENTS - 1) {
            elements[idx].next = &elements[idx + 1];
        } else {
            elements[idx].next = NULL;
        }
    }

    ptr_ = &elements[0];
}