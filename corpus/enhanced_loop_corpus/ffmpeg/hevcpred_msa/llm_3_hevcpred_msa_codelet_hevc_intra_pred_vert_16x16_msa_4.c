#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t arr[16];
    int32_t indices[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    for (col = 0; col < 16; col++) {
        arr[indices[col]] = col; // Indirect access: write using index mapping (reverse order)
    }
}
