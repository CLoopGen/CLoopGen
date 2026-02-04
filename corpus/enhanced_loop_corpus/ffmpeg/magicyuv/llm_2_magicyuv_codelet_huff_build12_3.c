#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern HuffEntry he[4096];
extern uint32_t codes[4096];
extern uint8_t bits[4096];
extern uint16_t syms[4096];
extern uint32_t code;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the iteration order to ascending
    // This changes the access pattern of 'he' from descending to ascending, improving spatial locality
    for (i = 0; i < 4096; i++) {
        int idx = 4095 - i; // reverse index to maintain original data dependency
        codes[idx] = code >> (32 - he[idx].len);
        bits[idx] = he[idx].len;
        syms[idx] = he[idx].sym;
        code += 2147483648U >> (he[idx].len - 1);
    }
}
