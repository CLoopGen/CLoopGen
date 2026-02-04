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
extern HuffEntry he[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 32; j++) {
        for (int k = 0; k < 32; k++) {
            int i = j * 32 + k;
            he[i].sym = i;
            he[i].len = *src++;
        }
    }
}
