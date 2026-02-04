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
    uint32_t local_code[256];
    local_code[255] = code;
    for (i = 255; i >= 0; i--) {
        he[i].code = local_code[i] >> (32 - he[i].len);
        if (i > 0) {
            local_code[i - 1] = local_code[i] + (2147483648U >> (he[i].len - 1));
        }
    }
    code = local_code[0];
}
