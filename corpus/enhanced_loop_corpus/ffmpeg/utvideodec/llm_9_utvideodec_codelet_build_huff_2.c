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
    int j;
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 4; j++) {
            int idx = (i << 2) | j;
            he[idx].sym = idx;
            he[idx].len = *src++;
        }
    }
}
