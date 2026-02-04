#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern HuffEntry he[256];
extern uint32_t codes[256];
extern uint8_t bits[256];
extern uint8_t syms[256];
extern uint32_t code;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing iteration order and accessing arrays sequentially
    for (i = 0; i < 256; i++) {
        int idx = 255 - i;
        codes[idx] = code >> (32 - he[idx].len);
        bits[idx] = he[idx].len;
        syms[idx] = he[idx].sym;
        code += 2147483648U >> (he[idx].len - 1);
    }
}
