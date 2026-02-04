#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int inner_i;
    int chunk_size = (2 * size - 1 + 3) / 4; // Approximate quarter of original range
    for (outer_i = 0; outer_i < 4; outer_i++) {
        int start = (2 * size - 2) - outer_i * chunk_size;
        int end = start - chunk_size + 1;
        if (end < -1) end = -1;
        for (inner_i = start; inner_i >= end && inner_i >= 0; inner_i--)
            filtered_top[inner_i] = (top[inner_i + 1] + 2 * top[inner_i] + top[inner_i - 1] + 2) >> 2;
    }
}
