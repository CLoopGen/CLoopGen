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
for (i = last; i >= 0; i--) {
    uint8_t length = he[i].len;
    codes[i] = code >> (32 - length);
    bits[i] = length;
    syms[i] = he[i].sym;
    if (length < 32) {
        code += 2147483648U >> (length - 1);
    }
}
}
