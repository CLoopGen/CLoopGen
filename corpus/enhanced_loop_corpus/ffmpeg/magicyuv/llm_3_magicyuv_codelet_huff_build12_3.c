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
    // Variant 2: Strided memory access with stride of 2, processing even and odd indices separately
    // First pass: process upper half in reverse with stride 2
    for (i = 4095; i >= 1; i -= 2) {
        int idx = i;
        codes[idx] = code >> (32 - he[idx].len);
        bits[idx] = he[idx].len;
        syms[idx] = he[idx].sym;
        code += 2147483648U >> (he[idx].len - 1);
    }
    // Second pass: handle remaining elements (odd indices if any left)
    for (i = 4094; i >= 0; i -= 2) {
        int idx = i;
        codes[idx] = code >> (32 - he[idx].len);
        bits[idx] = he[idx].len;
        syms[idx] = he[idx].sym;
        code += 2147483648U >> (he[idx].len - 1);
    }
}
