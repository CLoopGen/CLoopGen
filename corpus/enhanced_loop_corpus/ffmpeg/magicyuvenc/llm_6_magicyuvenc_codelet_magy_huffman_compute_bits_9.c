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
    uint8_t temp_sym;
    uint8_t temp_len;
    for (i = 0; i < size; i++) {
        temp_sym = i;
        temp_len = nbits[i];
        distincts[i].sym = temp_sym;
        distincts[i].len = temp_len;
    }
}
