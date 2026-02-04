#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *counter;
extern uint8_t *cur_pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping (reverse even indices first, then odd)
    int indices[] = {6, 4, 2, 0, 7, 5, 3, 1}; // Custom access order
    int count = 8;
    for (int j = 0; j < count; j++) {
        uint8_t *cur = counter + indices[j];
        (*cur)++;
        if (*cur != 0) {
            break;
        }
    }
}
