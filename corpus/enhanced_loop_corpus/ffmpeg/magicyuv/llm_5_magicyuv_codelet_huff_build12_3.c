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
for (i = 4095; i >= 0; i--) {
    uint8_t len = he[i].len;
    codes[i] = (len == 0) ? 0 : code >> (32 - len);
    bits[i] = len;
    syms[i] = he[i].sym;
    if (len > 0) {
        code += 2147483648U >> (len - 1);
    }
}
}
