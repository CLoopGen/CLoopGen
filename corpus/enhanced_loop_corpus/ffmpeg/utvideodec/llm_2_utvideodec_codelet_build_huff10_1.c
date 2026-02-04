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
extern HuffEntry he[1024];
extern int last;
extern uint32_t codes[1024];
extern uint8_t bits[1024];
extern uint16_t syms[1024];
extern uint32_t code;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (backward traversal with step)
    int stride = 2;
    for (i = (last / stride) * stride; i >= 0; i -= stride) {
        int j = i;  // current index
        codes[j] = code >> (32 - he[j].len);
        bits[j] = he[j].len;
        syms[j] = he[j].sym;
        code += 2147483648U >> (he[j].len - 1);
        
        if (i - 1 >= 0) {  // handle odd-sized arrays safely
            j = i - 1;
            codes[j] = code >> (32 - he[j].len);
            bits[j] = he[j].len;
            syms[j] = he[j].sym;
            code += 2147483648U >> (he[j].len - 1);
        }
    }
}
