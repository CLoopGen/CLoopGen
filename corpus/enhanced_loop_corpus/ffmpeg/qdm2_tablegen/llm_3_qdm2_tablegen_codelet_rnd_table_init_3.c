#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t random_dequant_type24[128][3];
extern int i;
extern int j;
extern uint32_t ldw;
extern uint64_t random_seed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use indirect access via pointer arithmetic to simulate consecutive byte-wise writes
    uint8_t (*base)[3] = &random_dequant_type24[0];
    for (i = 0; i < 128; i++) {
        random_seed = 25;
        ldw = i;
        uint8_t *row = (uint8_t *)((uintptr_t)base + i * sizeof(uint8_t[3])); // Consecutive memory access via byte offset
        for (j = 0; j < 3; j++) {
            row[j] = ldw / random_seed;
            ldw %= random_seed;
            random_seed /= 5;
        }
    }
}
