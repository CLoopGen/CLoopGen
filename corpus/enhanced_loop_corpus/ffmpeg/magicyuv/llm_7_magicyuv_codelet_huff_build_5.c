#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern HuffEntry he[256];
extern uint32_t codes[256];
extern uint8_t bits[256];
extern uint8_t syms[256];
extern uint32_t code;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_codes[256];
    uint8_t local_bits[256];
    uint8_t local_syms[256];
    uint32_t running_code = code;

    for (i = 255; i >= 0; i--) {
        uint16_t sym_val = he[i].sym;
        uint8_t len_val = he[i].len;
        uint32_t code_val = running_code >> (32 - len_val);

        local_syms[i] = sym_val;
        local_bits[i] = len_val;
        local_codes[i] = code_val;

        running_code += 2147483648U >> (len_val - 1);
    }

    for (i = 0; i < 256; i++) {
        codes[i] = local_codes[i];
        bits[i] = local_bits[i];
        syms[i] = local_syms[i];
    }
}
