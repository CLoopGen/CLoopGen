#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t arr[8] = {0};
    uint32_t indices[] = {1, 2, 3, 4, 5, 6, 7};
    for (col = 0; col < 7; col++) {
        arr[indices[col]] = col + 1; // Indirect access via index array
    }
}
