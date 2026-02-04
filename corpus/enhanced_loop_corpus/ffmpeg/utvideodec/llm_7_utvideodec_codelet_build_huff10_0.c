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
    uint16_t running_sym = 0;
    for (i = 0; i < 1024; i++) {
        running_sym += i;
        he[i].sym = running_sym;
        he[i].len = *src++;
        he[i].code = (uint32_t)(he[i].sym) << he[i].len;
    }
}
