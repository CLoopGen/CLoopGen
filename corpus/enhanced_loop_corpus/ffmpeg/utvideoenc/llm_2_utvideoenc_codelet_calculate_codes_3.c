#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern HuffEntry *he;
extern int last;
extern int i;
extern uint32_t code;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse, then handle remainder)
    int stride = 2;
    // First pass: process indices with stride
    for (i = last - (last % stride); i >= 0; i -= stride) {
        he[i].code = code >> (32 - he[i].len);
        code += 2147483648U >> (he[i].len - 1);
    }
    // Second pass: handle the odd-indexed elements if last was odd
    for (i = last - (last % stride ? 0 : 1); i >= 0; i -= stride) {
        if (i + 1 <= last && (i + 1) % stride == 1) {
            int j = i + 1;
            he[j].code = code >> (32 - he[j].len);
            code += 2147483648U >> (he[j].len - 1);
        }
    }
}
