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
    uint32_t temp_code = code;
    for (i = last; i >= 0; i--) {
        uint8_t current_len = he[i].len;
        codes[i] = temp_code >> (32 - current_len);
        bits[i] = current_len;
        syms[i] = he[i].sym;
        temp_code += 2147483648U >> (current_len - 1);
    }
}
