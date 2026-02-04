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
    for (i = 255; i >= 0; i--) {
        if (he[i].len > 0) {
            he[i].code = code >> (32 - he[i].len);
            code += 2147483648U >> (he[i].len - 1);
        }
    }
}
