#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern HuffEntry *he;
extern int last;
extern int i;
extern uint32_t code;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = last; i >= 0; i--) {
    he[i].code = code >> (32 - he[i].len);
    code += 2147483648U >> (he[i].len - 1);
}

}
