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
    for (i = 0; i < 256; i += 4) {
        he[i].sym = i;
        he[i].len = *src++;
        if (i + 1 < 256) {
            he[i+1].sym = i+1;
            he[i+1].len = *src++;
        }
        if (i + 2 < 256) {
            he[i+2].sym = i+2;
            he[i+2].len = *src++;
        }
        if (i + 3 < 256) {
            he[i+3].sym = i+3;
            he[i+3].len = *src++;
        }
    }
}
