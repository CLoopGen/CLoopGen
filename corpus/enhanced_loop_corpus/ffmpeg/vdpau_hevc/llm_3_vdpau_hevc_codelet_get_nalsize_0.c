#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nal_length_size;
extern  uint8_t *buf;
extern int *buf_index;
extern int i;
extern int nalsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order byte reading (from high to low address within the field)
    nalsize = 0;
    int start_index = *buf_index;
    int end_index = start_index + nal_length_size;
    for (i = 0; i < nal_length_size; i++) {
        int reverse_pos = end_index - 1 - i; // Access from end backwards
        nalsize = ((unsigned int)nalsize << 8) | buf[reverse_pos];
    }
    *buf_index = end_index; // Move buffer index forward after processing
}
