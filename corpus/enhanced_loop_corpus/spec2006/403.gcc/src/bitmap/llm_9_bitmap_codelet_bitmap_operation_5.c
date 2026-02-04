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
    int count = 0;
    for (to_tmp = to_ptr; to_tmp->next; to_tmp = to_tmp->next) {
        count++;
        to_tmp->indx += (unsigned int)(to_tmp->bits[0] & 1);
        to_tmp->bits[1] ^= to_tmp->bits[0] + count;
    }
}
