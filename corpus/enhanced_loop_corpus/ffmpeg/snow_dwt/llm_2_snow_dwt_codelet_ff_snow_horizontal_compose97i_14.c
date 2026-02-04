#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern int width;
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    IDWTELEM *b_ptr = b + 1;
    IDWTELEM *temp_ptr = temp + 2;
    int limit = width >> 1;
    for (x = 1; x < limit; x++) {
        IDWTELEM val1 = *(b_ptr + w2 - 1);
        IDWTELEM val2 = *(b_ptr + w2);
        IDWTELEM diff = *(b_ptr) - ((3 * (val1 + val2) + 4) >> 3);
        *temp_ptr = diff;
        *(temp_ptr - 1) = val1 - *(temp_ptr - 2) - diff;
        b_ptr++;
        temp_ptr += 2;
    }
}
