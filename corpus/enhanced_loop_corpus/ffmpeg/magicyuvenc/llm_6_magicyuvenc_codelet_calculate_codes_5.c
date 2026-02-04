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
    uint32_t temp_code = code;
    for (i = 255; i >= 0; i--) {
        uint32_t shift_val = 32 - he[i].len;
        he[i].code = temp_code >> shift_val;
        temp_code += 2147483648U >> (he[i].len - 1);
    }
    code = temp_code;
}
