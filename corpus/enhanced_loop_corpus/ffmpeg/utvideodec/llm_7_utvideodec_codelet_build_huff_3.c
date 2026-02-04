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
    int j;
    uint32_t local_code = code;
    for (i = last, j = 0; i >= 0; i--, j++) {
        codes[j] = local_code >> (32 - he[i].len);
        bits[j] = he[i].len;
        syms[j] = he[i].sym;
        local_code += 2147483648U >> (he[i].len - 1);
    }
    code = local_code;
}
