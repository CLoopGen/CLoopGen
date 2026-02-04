#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern uint8_t *recoded;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with reverse read access pattern
    int idx = buf_size - 3; // Start from near the end
    for (i = 2; i < buf_size - 2 && j < buf_size + 1024 - 2; i++) {
        recoded[j++] = buf[idx--];
    }
}
