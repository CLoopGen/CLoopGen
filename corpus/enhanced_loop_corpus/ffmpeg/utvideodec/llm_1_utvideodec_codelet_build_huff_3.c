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
    if (last >= 0) {
        for (i = last; i >= 0; i--) {
            {
                codes[i] = code >> (32 - he[i].len);
                bits[i] = he[i].len;
                syms[i] = he[i].sym;
                code += 2147483648U >> (he[i].len - 1);
            }
        }
    }
}
