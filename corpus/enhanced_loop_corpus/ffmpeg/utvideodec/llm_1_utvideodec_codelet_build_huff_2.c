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
    for (i = 0; i < 64; i++) {
        for (int k = 0; k < 4; k++) {
            int idx = i * 4 + k;
            he[idx].sym = idx;
            he[idx].len = *src++;
        }
    }
}
