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
    uint32_t temp_code = code;
    for (i = 255; i >= 0; i--) {
        uint8_t current_len = he[i].len;
        uint32_t shifted_code = temp_code >> (32 - current_len);
        codes[i] = shifted_code;
        bits[i] = current_len;
        syms[i] = he[i].sym;
        temp_code += 2147483648U >> (current_len - 1);
    }
}
