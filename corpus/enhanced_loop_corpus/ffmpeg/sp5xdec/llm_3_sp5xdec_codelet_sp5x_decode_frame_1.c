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
    // Variant 2: Consecutive write with pre-fetching and coalesced access pattern
    uint8_t temp[2];
    int count = 0;
    for (i = 14; i < buf_size && j + count < buf_size + 1024 - 3; i++) {
        temp[0] = buf[i];
        temp[1] = 0;
        recoded[j + count] = temp[0];
        count++;
        if (buf[i] == 255 && count < 2 && j + count < buf_size + 1024 - 3) {
            recoded[j + count] = temp[1];
            count++;
        }
    }
    j += count; // Update j after batched write simulation
}
