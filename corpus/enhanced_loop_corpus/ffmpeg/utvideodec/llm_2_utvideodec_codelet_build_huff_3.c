#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern int i;
extern HuffEntry he[256];
extern int last;
extern uint32_t codes[256];
extern uint8_t bits[256];
extern uint8_t syms[256];
extern uint32_t code;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access by reversing iteration order and accessing arrays sequentially from start
    int idx = 0;
    for (i = 0; i <= last; i++) {
        int rev_i = last - i;  // Reverse index to maintain original data dependency
        codes[idx] = code >> (32 - he[rev_i].len);
        bits[idx] = he[rev_i].len;
        syms[idx] = he[rev_i].sym;
        code += 2147483648U >> (he[rev_i].len - 1);
        idx++;
    }
}
