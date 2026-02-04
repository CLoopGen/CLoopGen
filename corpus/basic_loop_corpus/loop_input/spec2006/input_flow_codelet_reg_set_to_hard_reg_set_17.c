#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

typedef struct bitmap_element_def {
    struct bitmap_element_def *next;
    struct bitmap_element_def *prev;
    unsigned int indx;
    unsigned long bits[2];
} bitmap_element;

HARD_REG_ELT_TYPE *to;
int i;
bitmap_element *ptr_;
unsigned int bit_num_;
unsigned int word_num_;

#define ELEMENT_COUNT (1 << 14)  // ~16K elements, each with 2*64 bits -> ~2MB data
#define DATA_SIZE_MB 2

static bitmap_element *elements;
static HARD_REG_ELT_TYPE to_buffer[1024];

void init_vars() {
    // Initialize scalar variables
    i = 0;
    ptr_ = NULL;
    bit_num_ = 0;
    word_num_ = 0;

    // Allocate memory for elements
    elements = calloc(ELEMENT_COUNT, sizeof(bitmap_element));
    if (!elements) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Initialize buffer for 'to'
    memset(to_buffer, 0, sizeof(to_buffer));
    to = to_buffer;

    // Link the elements into a doubly-linked list
    for (int idx = 0; idx < ELEMENT_COUNT; idx++) {
        elements[idx].indx = idx;
        elements[idx].bits[0] = (idx % 3) ? ((unsigned long)(0xFULL << (idx * 5 % 56))) : 0;
        elements[idx].bits[1] = (idx % 7) ? ((unsigned long)(0x3FULL << (idx * 3 % 52))) : 0;
        
        if (idx > 0) {
            elements[idx].prev = &elements[idx - 1];
            elements[idx - 1].next = &elements[idx];
        } else {
            elements[idx].prev = NULL;
        }
        elements[idx].next = NULL;
    }

    // Set head of the list
    ptr_ = &elements[0];
}