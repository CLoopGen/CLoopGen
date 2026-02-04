#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint8_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern HuffEntry *he;
extern uint32_t code;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t shift_val;
    uint32_t base = 2147483648U;
    for (i = 255; i >= 0; i--) {
        shift_val = 32 - he[i].len;
        he[i].code = code >> shift_val;
        shift_val = he[i].len - 1;
        code += base >> shift_val;
    }
}
