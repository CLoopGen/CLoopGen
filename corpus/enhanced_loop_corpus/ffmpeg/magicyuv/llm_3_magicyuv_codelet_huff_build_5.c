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
    // Variant 2: Strided memory access with stride of 2, processing even indices first, then odd
    for (i = 254; i >= 0; i -= 2) {
        int idx = i + 1;
        codes[i] = code >> (32 - he[i].len);
        bits[i] = he[i].len;
        syms[i] = he[i].sym;
        code += 2147483648U >> (he[i].len - 1);

        codes[idx] = code >> (32 - he[idx].len);
        bits[idx] = he[idx].len;
        syms[idx] = he[idx].sym;
        code += 2147483648U >> (he[idx].len - 1);
    }
    // Handle index 0 if not covered (when starting from even)
    if (i == -1) {
        int idx = 0;
        codes[idx] = code >> (32 - he[idx].len);
        bits[idx] = he[idx].len;
        syms[idx] = he[idx].sym;
        code += 2147483648U >> (he[idx].len - 1);
    }
}
