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
    uint8_t *local_src = src;
    for (i = 0; i < 256; i++) {
        he[i].sym = i;
        he[i].len = local_src[i];
    }
    src += 256;
}
