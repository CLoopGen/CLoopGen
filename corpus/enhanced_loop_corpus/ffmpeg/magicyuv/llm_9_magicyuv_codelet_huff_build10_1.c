#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern HuffEntry he[1024];
extern uint32_t codes[1024];
extern uint8_t bits[1024];
extern uint16_t syms[1024];
extern uint32_t code;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_code = code;
    for (i = 1023; i >= 0; i--) {
        uint8_t len = he[i].len;
        codes[i] = temp_code >> (32 - len);
        bits[i] = len;
        syms[i] = he[i].sym;
        temp_code += 1U << (31 - (len - 1));
    }
    code = temp_code;
}
