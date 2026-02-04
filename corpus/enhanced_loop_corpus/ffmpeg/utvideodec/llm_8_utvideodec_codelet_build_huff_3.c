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



void loop(){
int start = last & ~3; // Align down to multiple of 4
for (i = start; i >= 0; i -= 4) {
    // Unroll loop by factor of 4 to increase computational intensity
    int idx0 = i;
    int idx1 = i - 1;
    int idx2 = i - 2;
    int idx3 = i - 3;

    if (idx0 <= last) {
        codes[idx0] = code >> (32 - he[idx0].len);
        bits[idx0] = he[idx0].len;
        syms[idx0] = he[idx0].sym;
        code += 2147483648U >> (he[idx0].len - 1);
    }
    if (idx1 >= 0) {
        codes[idx1] = code >> (32 - he[idx1].len);
        bits[idx1] = he[idx1].len;
        syms[idx1] = he[idx1].sym;
        code += 2147483648U >> (he[idx1].len - 1);
    }
    if (idx2 >= 0) {
        codes[idx2] = code >> (32 - he[idx2].len);
        bits[idx2] = he[idx2].len;
        syms[idx2] = he[idx2].sym;
        code += 2147483648U >> (he[idx2].len - 1);
    }
    if (idx3 >= 0) {
        codes[idx3] = code >> (32 - he[idx3].len);
        bits[idx3] = he[idx3].len;
        syms[idx3] = he[idx3].sym;
        code += 2147483648U >> (he[idx3].len - 1);
    }
}
// Handle remaining elements with reduced trip count
for (; i >= 0; i--) {
    codes[i] = code >> (32 - he[i].len);
    bits[i] = he[i].len;
    syms[i] = he[i].sym;
    code += 2147483648U >> (he[i].len - 1);
}
}
