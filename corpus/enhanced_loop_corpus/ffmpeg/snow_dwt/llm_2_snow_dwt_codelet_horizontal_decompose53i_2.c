#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

extern DWTELEM *b;
extern DWTELEM *temp;
extern  int width2;
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    DWTELEM *b_ptr = b;
    DWTELEM *temp_ptr = temp;
    DWTELEM *temp_ptr2 = temp + w2;
    for (x = 0; x < width2; x++) {
        *temp_ptr++ = *b_ptr;
        *temp_ptr2++ = *(b_ptr + 1);
        b_ptr += 2;
    }
}
