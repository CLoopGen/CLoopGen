#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *_usr_index;
extern int k;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Indirect memory access using a fixed offset table
    int access_pattern[] = {4, 5}; // Original indices accessed in order
    int num_elements = 2;
    for (int i = 0; i < num_elements; i++) {
        int k = access_pattern[i];
        if (index[k] >= 44 && index[k] < 108) {
            index[k] += 64;
        } else if (index[k] >= 108 && index[k] < 128) {
            index[k] += 128;
        }
    }
}
