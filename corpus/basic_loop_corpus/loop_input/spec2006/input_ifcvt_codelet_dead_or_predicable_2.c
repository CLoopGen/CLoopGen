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
#define DATA_SIZE (NUM_ELEMENTS * sizeof(bitmap_element))

static bitmap_element elements[NUM_ELEMENTS];

void init_vars() {
    i = 0;
    fail = 0;
    bit_num_ = 0;
    word_num_ = 0;

    memset(elements, 0, sizeof(elements));

    for (int idx = 0; idx < NUM_ELEMENTS; idx++) {
        elements[idx].indx = idx;
        elements[idx].next = (idx == NUM_ELEMENTS - 1) ? 0 : &elements[idx + 1];
        elements[idx].prev = (idx == 0) ? 0 : &elements[idx - 1];

        elements[idx].bits[0] = (idx % 3 == 0) ? (1UL << (idx % 64)) : 0;
        elements[idx].bits[1] = (idx % 5 == 0) ? (1UL << (idx % 64)) : 0;
    }

    ptr_ = &elements[0];
}