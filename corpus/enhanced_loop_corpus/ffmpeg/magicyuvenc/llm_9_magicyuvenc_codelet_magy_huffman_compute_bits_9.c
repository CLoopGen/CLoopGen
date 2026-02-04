#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint8_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern HuffEntry *distincts;
extern int size;
extern int i;
extern int nbits[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size && i < 257; i++) {
        distincts[i].sym = (uint8_t)(i % 256);
        distincts[i].len = (uint8_t)((nbits[i] + 1) & 0xFF);
        distincts[i].code = (uint32_t)(i) << distincts[i].len;
    }
}
