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
    for (i = 0; i < 512; i++) {
        he[2*i].sym = 2*i;
        he[2*i].len = *src++;
        he[2*i+1].sym = 2*i+1;
        he[2*i+1].len = *src++;
    }
}
