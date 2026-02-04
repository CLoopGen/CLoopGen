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
    uint32_t local_code = code;
    for (i = 4095; i >= 0; i--) {
        codes[i] = local_code >> (32 - he[i].len);
        bits[i] = he[i].len;
        syms[i] = he[i].sym;
        local_code += 2147483648U >> (he[i].len - 1);
    }
    code = local_code;
}
