#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        int inner_count = 0;
        // Simulate deeper logic with nested for-loop (depth increased)
        for (int j = i; j < i + 1 && j < size; j++, inner_count++) {
            if (src[inner_count] == 3 && j >= 2 && !src[inner_count - 1] && !src[inner_count - 2] && 
                j < size - 1 && src[inner_count + 1] < 4) {
                dst[dsize++] = src[inner_count + 1];
                src += 2;
                i++; // Compensate outer loop
            } else {
                dst[dsize++] = src[inner_count];
                src++;
            }
        }
    }
}
