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
int start = 0;
int end = 4096;
for (i = start; i < end; i++) {
    uint8_t len = he[i].len;
    codes[i] = code >> (32 - len);
    bits[i] = len;
    syms[i] = he[i].sym;
    code += 1U << (31 - (len - 1));
}
}
