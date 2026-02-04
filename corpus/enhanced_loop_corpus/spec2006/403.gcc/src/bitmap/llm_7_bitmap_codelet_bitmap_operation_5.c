#include <stdio.h>

#include <inttypes.h>

typedef struct bitmap_element_def {
    struct bitmap_element_def *next;
    struct bitmap_element_def *prev;
    unsigned int indx;
    unsigned long bits[2];
} bitmap_element;

extern bitmap_element *to_ptr;
extern bitmap_element *to_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    to_tmp = to_ptr;
    bitmap_element *next_ptr;
    for (; to_tmp && (next_ptr = to_tmp->next); ) {
        to_tmp = next_ptr;
    }
}
