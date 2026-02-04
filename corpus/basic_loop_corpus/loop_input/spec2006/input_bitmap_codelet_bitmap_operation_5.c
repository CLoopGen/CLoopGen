#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct bitmap_element_def {
    struct bitmap_element_def *next;
    struct bitmap_element_def *prev;
    unsigned int indx;
    unsigned long bits[2];
} bitmap_element;

bitmap_element *to_ptr;
bitmap_element *to_tmp;

#define NUM_ELEMENTS (1 << 20)

static bitmap_element elements[NUM_ELEMENTS];

void init_vars() {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        elements[i].indx = i;
        elements[i].bits[0] = 0x12345678UL + i;
        elements[i].bits[1] = 0x87654321UL + i;
        elements[i].prev = &elements[(i - 1 + NUM_ELEMENTS) % NUM_ELEMENTS];
        elements[i].next = &elements[(i + 1) % NUM_ELEMENTS];
    }
    // Break the circular structure to make next eventually become NULL
    elements[NUM_ELEMENTS - 1].next = NULL;

    to_ptr = &elements[0];
    to_tmp = NULL;
}