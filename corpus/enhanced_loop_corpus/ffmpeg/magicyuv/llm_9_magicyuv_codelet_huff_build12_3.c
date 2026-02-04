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
for (i = 4095; i >= 0; i -= 2) {
    uint32_t code1, code2;
    uint8_t len1 = he[i].len;
    uint8_t len2 = he[i-1].len;
    code1 = code >> (32 - len1);
    code2 = (code + (1U << (31 - (len1 - 1)))) >> (32 - len2);
    codes[i] = code1;
    codes[i-1] = code2;
    bits[i] = len1;
    bits[i-1] = len2;
    syms[i] = he[i].sym;
    syms[i-1] = he[i-1].sym;
    code += (1U << (31 - (len1 - 1))) + (1U << (31 - (len2 - 1)));
}
if (i == -1) {
    uint8_t len = he[0].len;
    codes[0] = code >> (32 - len);
    bits[0] = len;
    syms[0] = he[0].sym;
}
}
