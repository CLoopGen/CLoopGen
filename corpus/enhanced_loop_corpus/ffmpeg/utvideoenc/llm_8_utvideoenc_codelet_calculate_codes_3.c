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
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    // Unroll by 2 iterations to decrease loop overhead and increase arithmetic per iteration
    int i = last;
    if (i >= 0) {
        for (; i >= 1; i -= 2) {
            uint32_t shift1 = 32 - he[i].len;
            uint32_t shift2 = 32 - he[i-1].len;
            he[i].code = code >> shift1;
            code += 2147483648U >> (he[i].len - 1);
            he[i-1].code = code >> shift2;
            code += 2147483648U >> (he[i-1].len - 1);
        }
        // Handle remaining element if any
        if (i == 0) {
            he[i].code = code >> (32 - he[i].len);
            code += 2147483648U >> (he[i].len - 1);
        }
    }
}
