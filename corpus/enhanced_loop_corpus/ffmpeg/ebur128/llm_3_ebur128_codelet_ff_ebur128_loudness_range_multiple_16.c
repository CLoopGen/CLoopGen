#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t j;
extern size_t stl_size;
extern unsigned long hist[1000];
extern size_t _usr_index;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Consecutive reverse traversal (access array from end to start)
    size_t start = (index > 999) ? 999 : index;
    for (j = 999; j >= start; --j) {
        stl_size += hist[j];
        if (j == 0) break; // Prevent underflow on unsigned type
    }
}
