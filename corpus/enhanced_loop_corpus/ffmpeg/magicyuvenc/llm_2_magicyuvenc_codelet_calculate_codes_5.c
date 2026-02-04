#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint8_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern HuffEntry *he;
extern uint32_t code;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse, then cover the rest)
    int stride = 2;
    for (i = 255; i >= 1; i -= stride) {
        he[i].code = code >> (32 - he[i].len);
        code += 2147483648U >> (he[i].len - 1);
    }
    for (i = 254; i >= 0; i -= stride) {
        he[i].code = code >> (32 - he[i].len);
        code += 2147483648U >> (he[i].len - 1);
    }
}
