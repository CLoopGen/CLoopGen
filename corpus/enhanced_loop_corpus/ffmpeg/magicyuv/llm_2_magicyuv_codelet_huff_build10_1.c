#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern HuffEntry he[1024];
extern uint32_t codes[1024];
extern uint8_t bits[1024];
extern uint16_t syms[1024];
extern uint32_t code;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4 (unrolled-like pattern)
    // Accesses every 4th element in reverse order, then handles remaining elements
    int stride = 4;
    for (i = 1023; i >= 3; i -= stride) {
        codes[i] = code >> (32 - he[i].len);
        bits[i] = he[i].len;
        syms[i] = he[i].sym;
        code += 2147483648U >> (he[i].len - 1);

        codes[i-1] = code >> (32 - he[i-1].len);
        bits[i-1] = he[i-1].len;
        syms[i-1] = he[i-1].sym;
        code += 2147483648U >> (he[i-1].len - 1);

        codes[i-2] = code >> (32 - he[i-2].len);
        bits[i-2] = he[i-2].len;
        syms[i-2] = he[i-2].sym;
        code += 2147483648U >> (he[i-2].len - 1);

        codes[i-3] = code >> (32 - he[i-3].len);
        bits[i-3] = he[i-3].len;
        syms[i-3] = he[i-3].sym;
        code += 2147483648U >> (he[i-3].len - 1);
    }
    // Handle remaining elements
    for (; i >= 0; i--) {
        codes[i] = code >> (32 - he[i].len);
        bits[i] = he[i].len;
        syms[i] = he[i].sym;
        code += 2147483648U >> (he[i].len - 1);
    }
}
