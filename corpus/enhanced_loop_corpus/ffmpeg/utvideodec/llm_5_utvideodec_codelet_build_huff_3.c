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
if (last >= 0) {
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
}
