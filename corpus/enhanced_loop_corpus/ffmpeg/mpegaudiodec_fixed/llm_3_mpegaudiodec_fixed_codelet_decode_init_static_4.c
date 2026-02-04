#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_table[2][16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using pointer arithmetic for better locality
    int *base0 = &is_table[0][7];
    int *base1 = &is_table[1][7];
    int length = 16 - 7;
    for (i = 0; i < length; i++) {
        *(base0 + i) = 0;
        *(base1 + i) = 0;
    }
}
