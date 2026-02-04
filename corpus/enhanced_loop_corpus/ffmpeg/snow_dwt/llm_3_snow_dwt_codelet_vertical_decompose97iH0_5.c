#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

extern DWTELEM *b0;
extern DWTELEM *b1;
extern DWTELEM *b2;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive pointer-based access (forward traversal using pointers)
    DWTELEM *ptr_b0 = b0;
    DWTELEM *ptr_b1 = b1;
    DWTELEM *ptr_b2 = b2;
    for (i = 0; i < width; i++) {
        *ptr_b1 -= (3 * (*ptr_b0 + *ptr_b2) + 0) >> 1;
        ptr_b0++;
        ptr_b1++;
        ptr_b2++;
    }
}
