#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern  uint8_t *src;
extern int i;
extern HuffEntry he[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_sym[256];
    uint8_t temp_len[256];
    for (i = 0; i < 256; i++) {
        temp_sym[i] = i;
        temp_len[i] = *src++;
    }
    for (i = 0; i < 256; i++) {
        he[i].sym = temp_sym[i];
        he[i].len = temp_len[i];
    }
}
