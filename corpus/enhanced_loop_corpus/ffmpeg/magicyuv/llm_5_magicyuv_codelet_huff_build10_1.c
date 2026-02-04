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
    for (i = 1023; i >= 0; i--) {
        codes[i] = code >> (32 - he[i].len);
        bits[i] = he[i].len;
        syms[i] = he[i].sym;
        if (he[i].len <= 32) {
            code += 2147483648U >> (he[i].len - 1);
        }
    }
}
